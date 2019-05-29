//using of array with the pointers.
#include <iostream>
using namespace std;
int main(){
    int a[ 3 ] = { 1, 2, 3 };
    int *p = a;              // p = &a[ 0 ];

    cout << p[ 1 ] << endl;  // p[ 1 ] = 2 because pointer 'p' and array 'a' have the same adresses.

    cout << "before of accessed the array elements with pointer." << endl;
    cout << "a array : ";
    for ( int i = 0;  i < 3;  i++)  //
        cout << a[ i ] << " ";
    cout << "\np array : ";
    for ( int i = 0;  i < 3;  i++)
        cout << p[ i ] << " ";

    p[ 2 ] = 100;
    p[ 1 ] = 10;

    cout << "\n\nafter of accessed the array elements with pointer." << endl;
    cout << "a array : ";
    for ( int i = 0;  i < 3;  i++)  //
        cout << a[ i ] << " ";
    cout << "\np array : ";
    for ( int i = 0;  i < 3;  i++)
        cout << p[ i ] << " ";


    return 0;
}
