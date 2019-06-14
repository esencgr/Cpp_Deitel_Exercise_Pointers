// Functions can getting array or pointer as a  parameter. These ways are similar logic.
#include <iostream>
using namespace std;

// this function scales by 10 times each element of array.
int scale( int *a, int size ){
    // array method
    for ( int i = 0;  i < size;  i++)
        a [ i ] *= 10;

    /* pointer arithmetic
    for ( int i = 0;  i < 3;  i++)
        *( a + i ) *= 10;
    */
}

// this function sum each element of array.
int sum( int *a, int size){
   int sum = 0;
   // array method
   for ( int i = 0;  i < size;  i++)
       sum += a [ i ];

   /* pointer arithmetic
   for ( int i = 0;  i < 3;  i++)
       sum += *( a + i );
   */
   return sum;
}

int main(){
    int a[ 3 ] = {1, 2, 3};      // a is an array.
    int *a_ptr = a;              // a_ptr is a pointer to an array.

    cout << "\n array elements are scalling by 10 --> ";
    scale ( a, 3 );
    for ( int i = 0;  i < 3;  i++)
        cout << a[ i ] << " ";

    cout << "\n sum of array element --> " << sum( a, 3 ) << endl;

    return 0;
}
