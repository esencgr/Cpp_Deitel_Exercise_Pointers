// Using sizeof operator for different variables.
#include <iostream>
using namespace std;
int main(){
    int array[ 20 ];
    int *ptr; //= array;

    cout << " integer = " << sizeof( int ) << endl;
    cout << " double = " << sizeof( double ) << endl;
    cout << " float = " << sizeof( float ) << endl;
    cout << " char = " << sizeof( char ) << endl;
    cout << " short = " << sizeof( short ) << endl;
    cout << " long = " << sizeof( long ) << endl;
    cout << " long double = " << sizeof( long double ) << endl;
    cout << " int array = " << sizeof( array ) << endl;
    cout << " pointer = " << sizeof( ptr ) << endl;

    // In the int type variable returns 4 byte in memory and array's size of bytes
    // returns 80, also this is showing this array includes 80 / 4 = 20 elements.

    cout << " number of array's element = " << sizeof( array ) / sizeof( int );

    return 0;
}
