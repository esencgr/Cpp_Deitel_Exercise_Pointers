/* The determine of array elements is possible  four methods.
   Solution 0: Array identifier
   Solution 1: Pointer/offset method : the array name is used as a pointer.
   Solution 2: Using the pointer with identifier
   Solution 3: Pointer/offset method : the pointer arithmetic is used
*/
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
#define SIZE 5

int main(){

   int a[ SIZE ];
   int *a_ptr = a;
   srand (time ( 0 ));

   cout << "\nOriginal array --> ";
   for ( int i = 0; i < SIZE; i++) {
       a[ i ] = 1 + rand() % 100;    // a[ i ] = *( a_ptr + i )
       cout << a[ i ] << " ";
   }
    // Solution 0 : Array identifier
    cout << "\n\nArray identifier: " << endl;
    for ( int i = 0; i < SIZE; i++ )
        cout << "a[ " << i << " ]" << " --> " << a[ i ] << endl;

    // Solution 1 : Pointer/offset method : the array name is used as a pointer.
    cout << "\n\nPointer/offset method (the array name is used as a pointer): " << endl;
    for ( int offset = 0; offset < SIZE; offset++ )
        cout << "*( a+" << offset << " )" << " --> " << *( a + offset ) << endl;

    // Solution 2: Using the pointer with identifier
    cout << "\n\nWith dynamic memory method elements: " << endl;
    for ( int i = 0; i < SIZE; i++ )
        cout << "a[ " << i << " ]" << " --> " << a_ptr[ i ] << endl;

    // Solution 3: Pointer/offset method : the pointer arithmetic is used
    cout << "\n\nPointer/offset method (the pointer arithmetic is used): " << endl;
    for ( int offset = 0; offset < SIZE; offset++ )
          cout << "*( a_ptr+" << offset << " )"  " --> " << *( a_ptr + offset ) << endl;

    return 0;
}
