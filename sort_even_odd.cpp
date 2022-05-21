#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main ( int argc, char *argv[] )
{
    int InitArray[10] = {0};
    int temp = 0;
    int j = 0, k = 9;
    srand(time(NULL));
    for ( int i = 0; i < 10; i++ ) {
        InitArray[i] = rand();
        printf ( "%d ", InitArray[i] );
    };
    printf ( "\r\n" );
    while ( j < k ) {
        if ( InitArray[j] % 2 == 1 ) {
            j++;
            continue;
        }
        if ( InitArray[k] % 2 == 0 ) {
            k--;
            continue;
        }
        temp = InitArray[j];
        InitArray[j] = InitArray[k];
        InitArray[k] = temp;
        j++;
        k--;
    }
    for ( int i = 0; i < 10; i++ ) {
        printf ( "%d ", InitArray[i] );
    };
    printf ( "\r\n" );
    return 0;
}