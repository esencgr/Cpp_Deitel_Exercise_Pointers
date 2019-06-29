/* Mix and distribute a 10-card deck.*/
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void print( int [ ][ 2 ] );
void mix( int [ ][ 13 ] );
void distribute( const int [ ][ 13 ], const char *[], const char *[], int [][ 2 ] );
void pairs( const int [ ][ 13 ], const int [ ][ 2 ], const char *[] );
void three_of_kind( const int [ ][ 13 ], const int [ ][ 2 ], const char *[] );
void four_of_kind( const int [ ][ 13 ], const int [ ][ 2 ], const char *[] );
void flush_hand( const int [ ][ 13 ], const int [ ][ 2 ], const char *[] );
void straight( const int [ ][ 13 ], const int [ ][ 2 ], const char *[], const char *[] );

int main(){
    const char *firs[ 4 ] = { "kupa", "karo", "sinek", "maca" };
    const char *sec[ 13 ] = { "as", "iki", "uc", "dort", "bes", "alti", "yedi",
                              "sekiz","dokuz","on","vale","kiz","papaz" };
    int deck[ 4 ][ 13 ] = { 0 }, hand[ 10 ][ 2 ];

    srand( time( 0 ) );

    mix( deck );
    distribute( deck, firs, sec, hand);
    pairs( deck, hand, sec );
    three_of_kind( deck, hand, sec );
    four_of_kind( deck, hand, sec );
    flush_hand( deck, hand, firs);
    straight( deck, hand, firs, sec );

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

// deal a five card poker hand
void distribute( const int deck[ ][ 13 ], const char *first[], const char *second[], int hand[ ][ 2 ]){
    int r = 0;
    for ( int card = 1;  card <= 10;  card++ ){
        for ( int row = 0;  row <= 3;  row++ ){
            for ( int col = 0; col <= 12;  col++ ){
                if ( deck[ row ][ col ] == card ){
                    hand[ r ][ 0 ] = row;
                    hand[ r ][ 1 ] = col;
                    cout << first[ row ] << " " << second[ col ] << endl;
                    r++;
                }
            }
        }
    }
}

// pair determines if the hand contains one or two pair
void pairs( const int deck[ ][ 13 ], const int hand[ ][ 2 ], const char *second[] ){
    int counter[ 13 ] = { 0 };

    for ( int r = 0; r < 10; r++)
        ++counter[ hand [ r ][ 1 ] ];

    for ( int p = 0; p < 13; p++) {
        if ( counter[ p ] == 2 )
            cout << "\nThe hand contains pair  " << second[ p ] << endl;
    }
}

void three_of_kind( const int deck[ ][ 13 ], const int hand[ ][ 2 ], const char *second[] ){
    int counter[ 13 ] = { 0 };

    for ( int r = 0; r < 10; r++)
        ++counter[ hand [ r ][ 1 ] ];

    for ( int p = 0; p < 13; p++) {
        if ( counter[ p ] == 3 )
            cout << "\nThe hand contains three " << second[ p ] << endl;
    }
}

void four_of_kind( const int deck[ ][ 13 ], const int hand[ ][ 2 ], const char *second[] ){
    int counter[ 13 ] = { 0 };

    for ( int r = 0; r < 10; r++)
        ++counter[ hand [ r ][ 1 ] ];

    for ( int p = 0; p < 13; p++) {
        if ( counter[ p ] == 4 )
            cout << "\nThe hand contains four " << second[ p ] << endl;
    }
}

void flush_hand( const int deck[ ][ 13 ], const int hand[ ][ 2 ], const char *first[] ){
    int counter[ 4 ] = { 0 };

    for ( int r = 0; r < 10; r++)
        ++counter[ hand [ r ][ 0 ] ];

    for ( int p = 0; p < 10; p++){
        if ( counter[ p ] == 5 )
            cout << "\nThe hand contains flush " << first[ p ] << endl;
    }
}

void straight( const int deck[ ][ 13 ], const int hand[ ][ 2 ], const char *first[], const char *second[] ){
     int s[ 10 ] = { 0 }, temp;

     // copy column locations to sort
     for ( int r = 0; r < 10; r++)
         s[ r ] = hand[ r ][ 1 ];

     // bubble sort column locations
     for ( int pass = 1; pass < 10; pass++ ){
         for ( int comp = 0; comp < 4; comp++ ){
             if ( s[ comp ] > s[ comp + 1 ] ){
                 temp = s[ comp ];
                 s[ comp ] = s[ comp + 1 ];
                 s[ comp + 1 ] = temp;
              }
         }
     }

     // check if sorted columns are a straight
     if ( s[ 10 ] - 1 == s[ 9 ] && s[ 9 ] - 1 == s[ 8 ] && s[ 8 ] - 1 == s[ 7 ] && s[ 7 ] - 1 == s[ 6 ] &&
          s[ 6 ] - 1 == s[ 5 ] && s[ 5 ] - 1 == s[ 4 ] && s[ 4 ] - 1 == s[ 3 ] && s[ 3 ] - 1 == s[ 2 ] &&
          s[ 2 ] - 1 == s[ 1 ] && s[ 1 ] - 1 == s[ 0 ] ){
         cout << "\n The hand contains a straight consisting of\n";
         for ( int j = 0; j < 10; ++j )
             cout << second[ hand[ j ][ 1 ] ] << " of " << first[ hand[ j ][ 0 ] ] << '\n';
     }
}
