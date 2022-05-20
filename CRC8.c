#include <stdio.h>
#include <stdlib.h>

/*********************************************
*	Function: 	unsigned char CRC_8 ( unsigned char *ptr, int len )
*	Input:		pBuffer: Address of one array to calculate CRC_8 val
*				Size: size of bytes
*	Output:		CRC_8 value
*********************************************/
unsigned char CRC_8 ( unsigned char *ptr, int len )
{
    unsigned char CRC = 0;
    unsigned char i;
    while ( len-- ) {
        CRC = CRC^ *ptr++;
        for ( i = 0; i < 8; i++ ) {
            if ( CRC & 0x01 ) {
                CRC = ( CRC >> 1 ) ^ 0x8c; //x^8+x^5+x^4+1
            } else {
                CRC >>= 1;
            }
        }
    }
    return ( CRC );
}


unsigned char HextoInt ( unsigned char *ptr )
{
    unsigned char val = 0;
    if ( ptr[0] >= 'a' && ptr[0] <= 'f' ) {
        val = ptr[0] - 'a' + 10;
    } else if ( ptr[0] >= 'A' && ptr[0] <= 'F' ) {
        val = ptr[0] - 'A' + 10;
    } else if ( ptr[0] >= '0' && ptr[0] <= '9' ) {
        val = ptr[0] - '0';
    } else val = 0;
    val *= 16;

    if ( ptr[1] >= 'a' && ptr[1] <= 'f' ) {
        val += ptr[1] - 'a' + 10;
    } else if ( ptr[1] >= 'A' && ptr[1] <= 'F' ) {
        val += ptr[1] - 'A' + 10;
    } else if ( ptr[1] >= '0' && ptr[1] <= '9' ) {
        val += ptr[1] - '0';
    } else val = 0;
    return val;
}

int main ( int argc, char *argv[] )
{
    unsigned char CRC8 = 0;
    unsigned char *Datatptr = NULL;
    unsigned char Data[] = {0x5a, 0xa5, 0x05, 0x01};//CRC8=0xA1;

    Datatptr = ( unsigned char * ) malloc ( ( argc - 1 ) * sizeof ( unsigned char ) );
    for ( int i = 0; i < argc - 1; i++ ) {
        Datatptr[i] = ( unsigned char ) HextoInt ( argv[i + 1] );
        printf ( "%s-->%02X\r\n", argv[i + 1], Datatptr[i] );
    }
    //CRC8 = CRC_8 ( Data, sizeof ( Data ) );
    printf ( "CRC8 = %02X\n", CRC_8 ( Datatptr, argc - 1 ) );
    free ( Datatptr );
    return 0;
}