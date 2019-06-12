// Using sizeof operator is returned total bytes of array.
#include <iostream>
using namespace std;

size_t byte( double * );

int main(){
    double array[ 20 ];
    cout << " size of array = " << sizeof( array ) << endl;
    cout << " size of double = " << sizeof( double ) << endl;
    cout << " returned value by byte function = " << byte( array ) << endl;
    return 0;
}

size_t byte ( double *ptr ){
    return sizeof( ptr );
}
