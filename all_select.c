#include <stdio.h>
#define N 13

int a[N], b[N], count = 0;
int num = 0;
FILE *pf;

void comb ( int, int );
void print();
void swap ( int, int );


int main ( void )
{
    int i;
    int c[N] = {
        96,
        96,
        180,
        200,
        3999,
        3999,
        5627,
        6130,
        7840,
        8305,
        8952,
        8952,
        20000
    };
    pf = fopen ( "./result.txt", "w+" );
    for ( int  Choice = 1; Choice < N + 1; Choice++ ) {
        for ( i = 0; i < N; i++ ) {
            a[i] = c[i];
            b[i] = 0;
        }
        count = 0;
        comb ( N, Choice );
    }
    printf ( "total num is %d",num);
    fclose ( pf );
    return 0;
}

void comb ( int n, int m )
{
    int i;
    if ( m == 0 ) {
        print();
        return;
    } else {
        for ( int i = n - 1; i >= 0; i-- ) {
            b[m - 1] = a[i];
            comb ( i, m - 1 );
        }
    }
}


void print()
{
    int i;
    long int sum = 0;
    for ( i = 0; i < N; i++ ) {
        sum += b[i];
    }
    num++;
    fprintf ( pf,"%d,",sum );
}

void swap ( int i, int offset )
{
    int temp;
    temp = a[i];
    a[i] = a[offset];
    a[offset] = temp;
}
