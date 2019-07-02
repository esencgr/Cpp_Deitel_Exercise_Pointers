/* Mix and distribute a 52 card deck with optimized.
*/
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#define RACE_END 70
using namespace std;


void rabbit_move( int * const );
void turtoise_move( int * const );
void print_move( const int * const, const int *const );
void message( const int, const int , const int);

int main(){
    srand(time ( 0 ));
    int rabbit = 1, turtoise = 1, timer =0;


    while ( rabbit != RACE_END && turtoise != RACE_END ){
        rabbit_move( &rabbit );
        turtoise_move( &turtoise );
        print_move( &rabbit, &turtoise);
        timer++;
    }

    message ( rabbit, turtoise, timer );

    return 0;
}
void rabbit_move( int * const rabbit_ptr ){

    int dis = 1 + rand( ) % 10;

    if ( dis >= 3 && dis <= 4 )                    // big forward move
        *rabbit_ptr += 9;
    else if ( dis == 5 )                           // slip back move
        *rabbit_ptr -= 12;
    else if ( dis >= 6 && dis <= 8 )               // slow forward move
        *rabbit_ptr += 1;
    else if ( dis > 8 )
        *rabbit_ptr -= 2;

    if ( *rabbit_ptr < 1 )
        *rabbit_ptr = 1;
    else if( *rabbit_ptr > RACE_END )
        *rabbit_ptr = RACE_END;

}
void turtoise_move( int * const turtoise_ptr ){

    int dis = 1 + rand( ) % 10;

    if ( dis >= 1 && dis <= 5 )                    // fast forward move
        *turtoise_ptr += 3;
    else if ( dis >= 6 && dis <= 7 )               // slip back move
        *turtoise_ptr -= 6;
    else                                           // slow forward move
        *turtoise_ptr += 1;

    if ( *turtoise_ptr < 1 )
        *turtoise_ptr = 1;
    else if( *turtoise_ptr > RACE_END )
        *turtoise_ptr = RACE_END;

}
void print_move( const int * const rabbit_ptr, const int *const turtoise_ptr){

    char arr[ RACE_END ] = {'0'}, arr1[ RACE_END ] = {'0'}, arr2[ RACE_END ] = {'0'};

    if ( *rabbit_ptr == *turtoise_ptr ){
        for ( int i = 1; i <= RACE_END; i++) {
            if ( i <= *rabbit_ptr && i >= *rabbit_ptr  ){
                arr[ i ] = 'S';
            }
            else
                arr[ i ] = '-';
        }
        for (int i = 1; i <= RACE_END; i++ ) {
            cout << arr[ i ];
        }
    }

    else if ( *rabbit_ptr < *turtoise_ptr ){
        for ( int i = 1; i <= RACE_END; i++) {
            if ( i <= *rabbit_ptr && i >= *rabbit_ptr /*&& i <= *turtoise_ptr && i >= *turtoise_ptr*/ ){
                arr1[ i ] = 'R';
            }
            else if ( i <= *turtoise_ptr && i >= *turtoise_ptr ) {
                arr1[ i ] = 'T';
            }
            else
                arr1[ i ] = '-';
        }
        for (int i = 1; i <= RACE_END; i++ ) {
            cout << arr1[ i ];
        }

    }

    else{
        for ( int i = 1; i <= RACE_END; i++) {
            if (  i <= *turtoise_ptr && i >= *turtoise_ptr ){
                arr2[ i ] = 'T';
            }
            else if ( i <= *rabbit_ptr && i >= *rabbit_ptr ) {
                arr2[ i ] = 'R';
            }
            else
                arr2[ i ] = '-';
        }
        for (int i = 1; i <= RACE_END; i++ ) {
            cout << arr2[ i ];
        }
    }
    cout << endl;

}

void message( const int rabbit, const int turtoise, const int timer ){

   if ( turtoise >= rabbit )
       cout << " WINNER IS TURTOISE !! " << endl;
   else
       cout << " WINNER IS RABBIT !! " << endl;

   cout << " RACE TIME " << timer << "sec." << endl;
   
}

// void print_move( const int * const rabbit_ptr, const int *const turtoise_ptr){
//      char arr[ RACE_END ] = {'0'};
//     if ( *rabbit_ptr == *turtoise_ptr ){
//         cout << setw ( *rabbit_ptr ) <<  'S';
//     }
//     else if ( *rabbit_ptr < *turtoise_ptr ){
//         cout << setw ( *rabbit_ptr ) <<  'R';
//         cout << setw ( *turtoise_ptr - *rabbit_ptr ) << 'T';
//     }
//     else {
//         cout << setw ( *turtoise_ptr ) << 'T';
//         cout << setw ( *rabbit_ptr - *turtoise_ptr ) << 'R';
//     }
//     cout << endl;
//
// }

// MESSAGE
// if ( turtoise >= rabbit )
//     cout << " WINNER IS TURTOISE !! " << endl;
// else
//     cout << " WINNER IS RABBIT !! " << endl;
//
// cout << " RACE TIME " << timer << "sec." << endl;
