/* Mix and distribute a 10 card deck.*/
#include <iostream>
#include <ctime>
#include <cstdlib>
#define SIZE 10
using namespace std;


void mix( int [ ][ 13 ] );
void distribute( const int [ ][ 13 ], const char *[], const char *[], int [][ 2 ] , int [][ 2]);
void print( int [ ][ 2 ], int );
void compare_hands ( int hand[ ][ 2 ], int hand1[ ][ 2 ] );

// void bubble_sort( int [] );
// void pair_of_kind( const int [ ][ 13 ], const int [ ][ 2 ], const char *[] );
// void three_of_kind( const int [ ][ 13 ], const int [ ][ 2 ], const char *[] );
// void four_of_kind( const int [ ][ 13 ], const int [ ][ 2 ], const char *[] );
// void flush_hand( const int [ ][ 13 ], const int [ ][ 2 ], const char *[] );
// void straight( const int [ ][ 13 ],  int [ ][ 2 ], const char *[], const char *[] );
// void straight_check( int [], int [], const int [ ][ 13 ],  int [ ][ 2 ], const char *[], const char *[] );


int main(){
    const char *firs[ 4 ] = { "kupa", "karo", "sinek", "maca" };
    const char *sec[ 13 ] = { "as", "iki", "uc", "dort", "bes", "alti", "yedi",
                              "sekiz","dokuz","on","vale","kiz","papaz" };


    int deck[ 4 ][ 13 ] = { 0 }, hand1[ SIZE/2 ][ 2 ] = { 0 }, hand2[ SIZE/2 ][ 2 ] = { 0 };
    srand( time( 0 ) );

    mix( deck );
    distribute( deck, firs, sec, hand1, hand2);
    compare_hands ( hand1, hand2 );


    // pair_of_kind( deck, hand, sec );
    // three_of_kind( deck, hand, sec );
    // four_of_kind( deck, hand, sec );
    // flush_hand( deck, hand, firs);
    // straight( deck, hand, firs, sec );

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

// deal two five card pokers hand generated
void distribute( const int deck[ ][ 13 ], const char *first[], const char *second[], int hand[ ][ 2 ], int hand1[ ][ 2 ]){
    cout << "-- First Hand --" << endl;
    int f = 0;
    for ( int card = 1;  card <= SIZE/2; card++ ){
        for ( int row = 0;  row <= 3;  row++ ){
            for ( int col = 0; col <= 12;  col++ ){
                if ( deck[ row ][ col ] == card ){
                    hand[ f ][ 0 ] = row;
                    hand[ f ][ 1 ] = col;
                    cout << row << "-" << col << " --> " << first[ row ] << " " << second[ col ] << endl;
                    f++;
                }
            }
         }
     }

     cout << "\n-- Second Hand --" << endl;
     int s = 0;
     for ( int card = SIZE/2 + 1 ;  card <= SIZE;  card++ ){
         for ( int row1 = 0;  row1 <= 3;  row1++ ){
             for ( int col1 = 0; col1 <= 12;  col1++ ){
                 if ( deck[ row1 ][ col1 ] == card ){
                     hand1[ s ][ 0 ] = row1;
                     hand1[ s ][ 1 ] = col1;
                     cout << row1 << "-" << col1 << " --> " << first[ row1 ] << " " << second[ col1 ] << endl;
                     s++;
                 }
             }
         }
     }

}

void print( int s[], int size ){
    for ( int i = 0; i < size; i++){
        cout << s[ i ] << " ";
    }
}

void compare_hands ( int hand[ ][ 2 ], int hand1[ ][ 2 ]){

    // copy column and row locations
    int first_hand_suit [ SIZE/2 ] = { 0 }, second_hand_suit[ SIZE/2 ] = { 0 };
    int first_hand_face [ SIZE/2 ] = { 0 }, second_hand_face[ SIZE/2 ] = { 0 };

    cout << "\nFirst Hand Suit: " << endl;
    for ( int r = 0; r < SIZE/2; r++)
        first_hand_suit[ r ] = hand[ r ][ 0 ];

    print( first_hand_suit , SIZE/2 );
    cout << endl;

    cout << "\nSecond Hand Suit : " << endl;
    for ( int r = 0; r < SIZE/2; r++)
        second_hand_suit[ r ] = hand1[ r ][ 0 ];

    print( second_hand_suit , SIZE/2 );
    cout << endl;

    cout << "\nFirst Hand Face: " << endl;
    for ( int r = 0; r < SIZE/2; r++)
        first_hand_face[ r ] = hand[ r ][ 1 ];

    print( first_hand_face , SIZE/2 );
    cout << endl;

    cout << "\nSecond Hand Face : " << endl;
    for ( int r = 0; r < SIZE/2; r++)
        second_hand_face[ r ] = hand1[ r ][ 1 ];

    print( second_hand_face , SIZE/2 );
    cout << endl;

    // compare two hand row and row col and col positions. And calculate score
    int point_hand1 = 0, point_hand2 = 0;
    for (int x = 0; x < SIZE/2;  x++){

             if ( first_hand_suit[ x ] > second_hand_suit [ x ] )
                 point_hand1++;

             else if ( first_hand_suit[ x ] < second_hand_suit [ x ] )
                 point_hand2++;

             else{
             // if (first_hand_suit[ x ] == second_hand_suit [ x ] ){
                 if ( first_hand_face[ x ] > second_hand_face [ x ] )
                     point_hand1++;

                 else if ( first_hand_face[ x ] < second_hand_face [ x ] )
                     point_hand2++;
             }

    }
    cout << "\nHand_1 score : " << point_hand1 << endl;
    cout << "Hand_2 score : " << point_hand2 << endl;
}


// void bubble_sort( int s[] ){
//     int temp;
//     // bubble sort column locations
//     for ( int pass = 1; pass < SIZE; pass++ ){
//         for ( int comp = 0; comp < SIZE-1; comp++ ){
//             if ( s[ comp ] > s[ comp + 1 ] ){
//                 temp = s[ comp ];
//                 s[ comp ] = s[ comp + 1 ];
//                 s[ comp + 1 ] = temp;
//              }
//         }
//     }
// }



// // pair determines if the hand contains one or two pair
// void pair_of_kind( const int deck[ ][ 13 ], const int hand[ ][ 2 ], const char *second[] ){
//     int counter[ 13 ] = { 0 };
//
//     for ( int r = 0; r < SIZE; r++)
//         ++counter[ hand [ r ][ 1 ] ];
//
//     for ( int p = 0; p < 13; p++) {
//         if ( counter[ p ] == 2 )
//             cout << "\nThe hand contains pair  " << second[ p ] << endl;
//     }
// }
//
// void three_of_kind( const int deck[ ][ 13 ], const int hand[ ][ 2 ], const char *second[] ){
//     int counter[ 13 ] = { 0 };
//
//     for ( int r = 0; r < SIZE; r++)
//         ++counter[ hand [ r ][ 1 ] ];
//
//     for ( int p = 0; p < 13; p++) {
//         if ( counter[ p ] == 3 )
//             cout << "\nThe hand contains three " << second[ p ] << endl;
//     }
// }
//
// void four_of_kind( const int deck[ ][ 13 ], const int hand[ ][ 2 ], const char *second[] ){
//     int counter[ 13 ] = { 0 };
//
//     for ( int r = 0; r < SIZE;  r++)
//         ++counter[ hand [ r ][ 1 ] ];
//
//     for ( int p = 0; p < 13; p++) {
//         if ( counter[ p ] == 4 )
//             cout << "\nThe hand contains four " << second[ p ] << endl;
//     }
// }
//
// void flush_hand( const int deck[ ][ 13 ], const int hand[ ][ 2 ], const char *first[] ){
//     int counter[ 4 ] = { 0 };
//
//     for ( int r = 0; r < SIZE;  r++)
//         ++counter[ hand [ r ][ 0 ] ];
//
//     for ( int p = 0; p < SIZE;  p++){
//         if ( counter[ p ] == 5 )
//             cout << "\nThe hand contains flush " << first[ p ] << endl;
//     }
// }
//
// void straight( const int deck[ ][ 13 ],  int hand[ ][ 2 ], const char *first[], const char *second[] ){
//     int s[ SIZE ] = { 0 }, f[ SIZE ] = { 0 }, temp;
//
//     // copy column locations
//     cout << "\nindeces location : " << endl;
//     for ( int r = 0; r < SIZE; r++)
//         s[ r ] = hand[ r ][ 1 ];
//
//     // copy row locations
//     cout << "\nindeces location : " << endl;
//     for ( int k = 0; k < SIZE; k++)
//         f[ k ] = hand[ k ][ 0 ];
//
//     print ( s, SIZE );
//     cout << endl;
//
//     print ( f, SIZE );
//     cout << endl;
//
//     // bubble sort column locations
//     cout << "\nindeces sorted : " << endl;
//     bubble_sort ( s );
//     print ( s , SIZE);
//
//     // check if sorted columns and rows are a straight
//     cout << endl;
//     straight_check( s, f, deck, hand, first , second );
//
// }
//
// void straight_check( int s[], int f [], const int deck[ ][ 13 ],  int hand[ ][ 2 ], const char *first[], const char *second[] ){
//     cout << "\nThe hand contains a straight consisting of";
//     int temp;
//     for ( int j = 1; j <= SIZE; j++ ){
//         if ( s[ j ] - 1 == s[ j - 1 ] ){
//               for ( int i = 1; i <= SIZE; i++){
//                   if ( s[ j ] == hand [ i ][ 1 ]){
//                      // cout << "\n indis : " << i << endl;
//                      temp = i;
//                   }
//               }
//               cout << "\n" << f [ temp ] << " -> " <<  s[ j ] << '\n';
//               cout << "\n" << first[ f [ temp  ]] << " -> " <<  second[ s[ j ] ]  << '\n';
//         }
//     }
// }
// // deal a five card poker hand
// void distribute( const int deck[ ][ 13 ], const char *first[], const char *second[], int hand[ ][ 2 ]){
//     int r = 0;
//     for ( int card = 1;  card <= SIZE; card++ ){
//         for ( int row = 0;  row <= 3;  row++ ){
//             for ( int col = 0; col <= 12;  col++ ){
//                 if ( deck[ row ][ col ] == card ){
//                     hand[ r ][ 0 ] = row;
//                     hand[ r ][ 1 ] = col;
//                     cout << row << "-" << col << " --> " << first[ row ] << " " << second[ col ] << endl;
//                     r++;
//                 }
//             }
//         }
//     }
// }
