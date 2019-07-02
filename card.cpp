/* Mix and distribute a 52 card deck with optimized.*/
#include <iostream>
#include <ctime>
#include <cstdlib>
#define SIZE 10
using namespace std;


void shuffle( int [ ][ 13 ] );
void deal( const int [ ][ 13 ], const char *[], const char *[]);
void shuffle_deal( int deck[ ][ 13 ], const char *[], const char *[] );
void print( const int [ ][ 13 ] );

int main(){
    const char *suit[ 4 ] = { "kupa", "karo", "sinek", "maca" };
    const char *face[ 13 ] = { "as", "iki", "uc", "dort", "bes", "alti", "yedi",
                              "sekiz","dokuz","on","vale","kiz","papaz" };
    int deck[ 4 ][ 13 ] = { 0 }, card = 1;

    // initialze deck
    for ( int row = 0; row <= 3; row++ ){
        for ( int col = 0; col <=12; col++){
            deck [ row ][ col ] = card++;
        }
    }
    print( deck );
    cout << endl;

    srand( time ( 0 ));
    shuffle( deck );
    print( deck );
    cout << endl;

    deal( deck, suit, face );

    cout << " \n HAND 2 : " << endl;
    shuffle_deal ( deck, suit, face );

    return 0;
}
// shuffle all card before deal them.
void shuffle( int deck[ ][ 13 ] ){
     int temp, rand_row, rand_col;
     for ( int row = 0; row <= 3; row++ ){
         for ( int col = 0; col <=12; col++){
              rand_row = rand() % 4;
              rand_col = rand() % 13;
              temp = deck[ row ][ col ];
              deck[ row ][ col ] = deck[ rand_row ][ rand_col ];
              deck[ rand_row ][ rand_col ] = temp;
         }
     }
}

// deal all 52 card.
void deal( const int deck[ ][ 13 ], const char *suit[], const char *face[]){
     for (int card = 1; card <= 52; card++){
         for (int row = 0; row <= 3; row++){
             for (int col = 0; col <= 12; col++){
                  if ( deck[ row ][ col ] == card )
                      cout << suit[ row ] << " --> " << face[ col ] << endl;
             }
         }
     }
}
//shuffle and deal all card.
void shuffle_deal( int deck[ ][ 13 ], const char *suit[], const char *face[] ){
    int temp, rand_row, rand_col;
    for ( int card = 1; card <= 52; card++ ){
        for ( int row = 0; row <= 3; row++ ){
            for ( int col = 0; col <=12; col++ ){
                rand_row = rand() % 4;
                rand_col = rand() % 13;
                temp = deck[ row ][ col ];
                deck[ row ][ col ] = deck[ rand_row ][ rand_col ];
                deck[ rand_row ][ rand_col ] = temp;
                if ( deck[ row ][ col ] == card )
                    cout << suit[ row ] << " --> " << face[ col ] << endl;
            }
        }
    }
}
void print ( const int deck[ ][ 13 ] ){
    for ( int row = 0; row <= 3; row++ ){
        for ( int col = 0; col <=12; col++){
            cout << deck[ row ][ col ] << "\t";
        }
        cout << endl;
    }
}
