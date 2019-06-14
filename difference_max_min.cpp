/* Functions can getting array or pointer as a  parameter. These ways are similar
   logic.This code is calculate the difference of max and min elements of an array
   with pointers and dynamic memory management.
*/
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
#define SIZE 5

// This function is calculate the difference of max and min elements of an array
int diff( int *a, int size){
   // for reach the size of  array --> sizeof( array ) / sizeof( int )
   // size = sizeof ( a ) / sizeof( int ) 
   int max = *a;      // *a = a[ 0 ];
   int min = *a;      // *a = a[ 0 ];

   for ( int i = 0;  i < size;  i++){
       if ( a[ i ] < min )
          min = a[ i ];
       if ( a[ i ] > max )
          max = a[ i ];
   }
   return max - min;
}

int main(){
    int a[ SIZE ];
    int *a_ptr = a;
    srand (time ( 0 ));

    cout << "\n original array --> ";
    for ( int i = 0; i < SIZE; i++) {
        a[ i ] = 1 + rand() % 100;    // a[ i ] = *( a_ptr + i )
        cout << a[ i ] << " ";
    }

    cout << "\n\ndifference of max - min --> ";
    cout << diff( a, SIZE );          // a = *a_ptr

    return 0;
}
