#include <iostream>
using namespace std;

char *OriginalName[10] = {
    "Lin",
    "Mary",
    "Lee",
    "Jesika",
    "Rani",
    "Michelle",
    "Saeed",
    "Madison",
    "Samir",
    "Rachel"
};

int main ( int argc, char **argv )
{
    char *Array[10] = {NULL};
    char *temp = NULL;
    char Order = 0;
    int k = 0;
    Array[0] = OriginalName[0];
start:
    cout << "[Y or y] for ascending order and [N or n] for descending order\r" << endl;
    cin >> Order;
    if ( Order == 'Y' || Order == 'y' ) {
        Order = 1;
    } else if ( Order == 'N' || Order == 'n' ) {
        Order = 0;
    } else {
        cout << "Wrong order, enter again.\r" << endl;
        goto start;
    }

    for ( int i = 1; i < 10; i++ ) {
        Array[i] = OriginalName[i];
        for ( int j = i; j > 0 ; j-- ) {
            do {
                if ( ( Order == 1 && Array[j][k] < Array[j - 1][k] )
                     || ( Order == 0 && Array[j][k] > Array[j - 1][k] ) ) {
                    temp = Array[j];
                    Array[j] = Array[j - 1];
                    Array[j - 1] = temp;
                } else if ( Array[j][k] == Array[j - 1][k] ) {
                    k++;
                } else {
                    k = 0;
                    break;
                }
            } while ( Array[j][k] != '\0' && Array[j - 1][k] != '\0' );
        }
    }
    for ( int i = 0; i < 10; i++ ) {
        cout << "\r" << Array[i] << endl;
    }
    return 0;
}