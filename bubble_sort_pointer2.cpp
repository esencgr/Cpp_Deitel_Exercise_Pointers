// bubble sort  using call by reference
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void bubble( int *, const int );
void change( int *, int * );
void bubble_2( int [], const int );
void change_2( int, int );

int main(){
    srand(time ( NULL ));

    int size;
    cout << "enter size : " << endl;
    cin >> size;

    int array[ size ];
    cout << "Original order : " << endl;
    for ( int i = 0;  i < size;  i++){
        array[ i ] = 1 + rand( ) % 100;
        cout << array[ i ] << " ";
    }

    cout << "\n\nBubble sort order : " << endl;
    bubble_2( array, size );
    for ( int i = 0;  i < size;  i++)
        cout << array[ i ] << " ";

    return 0;
}
/* These functions are use pointers and fixed size variable.And changed function
   must access in the bubble function's array's elemnts. For this reason we can
   uses call by reference. If we were not used a pointer in these functions, we
   cant access the elements of array..*/
void bubble( int *arr, const int size ){
    //void change( int *, int * );
    for ( int i = 0;  i < size-1;  i++){
        for ( int j = 0;  j < size-1;  j++){
            if ( arr[ j ] > arr[ j+1 ] )
                change( &arr[ j ], &arr[ j+1 ]);
        }
    }
}
void change( int *e1_ptr, int *e2_ptr ){
    int temp = *e1_ptr;
    *e1_ptr = *e2_ptr;
    *e2_ptr = temp;
}

/* These function are use a array and fixed size variable.And changed function
   must access in the bubble function's array's elements. We did not use the
   pointer in these functions.We could'nt access the elements of array. And we
   couldn't set the array with order..*/

void bubble_2 ( int arr[], const int size ){
    for ( int i = 0;  i < size-1;  i++){
        for ( int j = 0;  j < size-1;  j++){
            if ( arr[ j ] > arr[ j+1 ] )
                change_2( arr[ j ], arr[ j+1 ]);
        }
    }
}
void change_2( int e1, int e2 ){
    int temp = e1;
    e1 = e2;
    e2 = temp;
}
