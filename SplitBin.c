//************************************************************************************
* Function		:	
* Input			:	
* Output		:	
* Description	:	split binary file into target pieces
* Author		:	Jc Tu
* Date 			:	2022-05-20
* 
* Log			:	
* No.	Date 		Revised by		Item Description
* 001	2022-05-20	Jc Tu		First created
*************************************************************************************/

#include "stdio.h"


int main ( int argc, char *argv[] )
{
    int sub_file_number = 0;
    unsigned int long src_file_length = 0;
    unsigned int long sub_file_length = 0;
    unsigned int long Splitlen = 0;
    char TempName[20] = {0};
    char TempBuffer[1024] = {0};
    unsigned int long readRC = 0, writeRC = 0;
    FILE *pf_src = NULL;
    FILE *pf_sub = NULL;
    if ( argc != 3 ) {
        printf ( "Usage: parameters wrong, expected 3, like:\r\n SplitBin **.bin 0x1000" );
        return 1;
    };

    if ( argv[2][0] > '0' && argv[2][0] <= '9' && argv[2][1] == '\0' ) {
        sub_file_number = argv[2][0] - '0';
    } else {
        printf ( "Usage: third parameters wrong, expected a number which is no-zero and not beyond 10 .\r\n" );
        return 2;
    }

    pf_src = fopen ( argv[1], "rb" );
    if ( pf_src == NULL ) {
        printf ( "%s file open failed\r\n", argv[1] );
        return 3;
    }
    fseek ( pf_src, 0, SEEK_END );
    src_file_length = ftell ( pf_src );
    fseek ( pf_src, 0, SEEK_SET );

    if ( src_file_length % sub_file_number != 0 ) {
        printf ( "file length: %ld, mod %d is not equal 0, check file and split number again.\n", src_file_length, sub_file_number );
        return 4;
    }

    for ( int i = 0; i < sub_file_number; i++ ) {
        sprintf ( TempName, "BinPart%d.bin", i + 1 );
        pf_sub = fopen ( TempName, "w+b" );
        sub_file_length = src_file_length / sub_file_number;

        while ( sub_file_length > 0 ) {
            Splitlen = sub_file_length > sizeof ( TempBuffer ) ? sizeof ( TempBuffer ) : sub_file_length;
            //printf ( "sub_file_length: %ld, read buffer length:%ld\n", sub_file_length, Splitlen );
            readRC = fread ( TempBuffer, sizeof ( char ),  Splitlen, pf_src );
            if ( readRC == 0 ) {
                printf ( "read error\n" );
                break;
            }
            writeRC = fwrite ( TempBuffer,  sizeof ( char ), readRC, pf_sub );
            sub_file_length -= writeRC;
        }
        fclose ( pf_sub );
    }
    fclose ( pf_src );
    return 0;
}