// bubble sort  using call by reference
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
#define SIZE 10

void bubble( int *, const int );
//void change( int *, int * );

int main(){
    srand(time ( NULL ));

    int array[ SIZE ];
    cout << "Original order : " << endl;
    for ( int i = 0;  i < SIZE;  i++){
        array[ i ] = 1 + rand( ) % 100;
        cout << array[ i ] << " ";
    }

    cout << "\n\nBubble sort order : " << endl;
    bubble ( array, SIZE );
    for ( int i = 0;  i < SIZE;  i++)
        cout << array[ i ] << " ";

    return 0;
}

/* This function is uses a pointer and fixed size variable.
   And changed function must access in the bubble function's array's elemnts.
   For this reason we can uses call by reference. If we were not used a pointer
   in these functions, we cant access the elements of array..*/

void bubble( int *arr, const int size ){
    void change( int *, int * );
    for ( int i = 0;  i < size-1;  i++){
        for ( int j = 0;  j < size-1;  j++){
            if ( arr[ j ] > arr[ j+1 ] )
                change ( &arr[ j ], &arr[ j+1 ]);
        }
    }
}

void change( int *e1_ptr, int *e2_ptr ){
    int temp = *e1_ptr;
    *e1_ptr = *e2_ptr;
    *e2_ptr = temp;
}
