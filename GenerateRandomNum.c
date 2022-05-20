#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANGE 10000
#define NUMBER 2000

int main ( int argc, char* argv[] )
{
    FILE* fp = NULL;
    char TempNumber[6] = {0};
    int Range, Number;
    if ( argc != 4 ) {
        printf ( "Usage: need 4 parameters, like \"*.exe *.txt [Range]10 [Number]1000\" \n" );
        return 0;
    }
    Range = atoi ( argv[2] );
    Number = atoi ( argv[3] );

    fp = fopen ( argv[1], "w+" );
    if ( fp == NULL ) {
        printf ( "Open file: %s failed", argv[1] );
        return 1;
    }

    srand ( ( unsigned ) time ( NULL ) );
    for ( int i = 0; i < Number; i++ ) {
        fputs ( itoa (rand () % Range, TempNumber, 10 ), fp );
        fputc ( '\r', fp );
    }
    fclose ( fp );
    return 0;
}
