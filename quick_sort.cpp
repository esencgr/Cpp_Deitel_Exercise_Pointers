/*
quick sort algorithm
*/
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

const int SIZE = 10;

void rand_array ( int *, const int );
void print( int *, const int );
void swap( int *, int * );
void quicksort( int * const, int, int );

int main(){

    srand(time ( NULL ));

    int array[ SIZE ];
    cout << " Original order : ";
    rand_array ( array, SIZE );
    print ( array, SIZE );

    cout << "\n Sorted order : ";
    quicksort( array, 0, SIZE - 1 );
    print ( array, SIZE );

    // if ( SIZE == 1 )
    //    cout << "Array is sorted: " << array[ 0 ] << '\n';
    // else {
    //    quicksort( array, 0, SIZE - 1 );
    //    cout << "The sorted array values are:\n";
    //    print ( array, SIZE );
    // }

    return 0;
}

void rand_array ( int *array, const int SIZE ){
    for ( int i = 0;  i < SIZE;  i++ )
        array[ i ] = 1 + rand( ) % 100;
}

void print( int *array, const int SIZE ){
    for ( int i = 0;  i < SIZE;  i++ )
        cout << array[ i ] << " " ;
}

void quicksort( int * const array, int first, int last ){
    int partition ( int * const , int, int );
    int current_loc;

    if ( first >= last )
        return;

    current_loc = partition( array, first, last ); // place an element
    quicksort( array, first, current_loc - 1 ); // sort left side
    quicksort( array, current_loc + 1, last ); // sort right side
}

int partition ( int * const array, int left, int right ){
    int position = left;
    while ( true ){
        while ( array[ position ] <= array[ right ] && position != right )
            right--;

        if ( position == right )
            return position;

        if ( array[ position ] > array[ right ] ){
            swap( &array[ position ], &array[ right ] );
            position = right;
        }

        while ( array[ left ] <= array[ position ] && left != position )
            left++;

        if ( position == left )
            return position;

        if ( array[ left ] > array[ position ] ){
            swap( &array[ position ], &array[ left ] );
            position = left;
        }
    }
}

void swap( int *e1_ptr, int *e2_ptr ){
    int temp;
    temp = *e1_ptr;
    *e1_ptr = *e2_ptr;
    *e2_ptr = temp;
}
