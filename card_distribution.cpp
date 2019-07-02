/* Cpp DEITEL EXERCISE 7.14
 Mix and distribute a 52-card deck.*/
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void mix( int [ ][ 13 ] );
void distribute( const int [ ][ 13 ], const char *[], const char *[] );

int main(){
    const char *firs[ 4 ] = { "kupa", "karo", "sinek", "maca" };
    const char *sec[ 13 ] = { "as", "iki", "uc", "dort", "bes", "alti", "yedi",
                              "sekiz","dokuz","on","vale","kiz","papaz" };
    int deck[ 4 ][ 13 ] = { 0 };

    srand( time( 0 ) );

    mix( deck );
    distribute( deck, firs, sec );

    return 0;
}

void mix( int deck[ ][ 13 ] ){
    int row, col, card;
    for ( int card = 1;  card <= 52;  card++ ){
        do{
           row = rand() % 4;
           col = rand() % 13;
        }while ( deck[ row ][ col ] != 0 );
        deck[ row ][ col ] = card;
    }
}

void distribute( const int deck[ ][ 13 ], const char *first[], const char *second[]){
    for ( int card = 1;  card <= 52;  card++ ){
        for ( int row = 0;  row < 4;  row++ ){
            for ( int col = 0; col < 13;  col++ ){
                if ( deck[ row ][ col ] == card ){
                    cout << first[ row ] << " " << second[ col ] << endl;
                }
            }
        }
    }
}
