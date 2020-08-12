/* Get numbers by user. It is possible that 4 following solutions.
   Solution 0: Classical method
   Solution 1: With an array
   Solution 2: With dynamic memory
   Solution 3: With pointer arithmetic
*/
#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){

    // Solution 0 : Classical method
    /*
       It is not guaranteed include this variables sequential located in RAM for this
       use. We don't know this variables address. C++ is decides to address of each
       variable .
    */
    cout << "\nClassical method elements: ";
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    cout << &a << " --> " << a << endl << &b << " --> " << b << endl
         << &c << " --> " << c << endl << &d << " --> " << d << endl
         << &e << " --> " << e ;

    /*
       In the other solutions in the below are guaranteed that this variables sequential
       locate in RAM.We know this variables addresses and these addresses are sequential.
       We can decides variables locate in RAM by ourselves.
    */
    // Solution 1 : With an array
    cout << "\n\nWith an array method elements: ";
    int k[ 5 ];
    for ( int i = 0; i < 5; i++ )
        cin >> k[ i ];

    for ( int i = 0; i < 5; i++ )
        cout << &k[ i ] << " --> " << k[ i ] << endl;

    // Solution 2: With dynamic memory(using pointer)
    cout << "\n\nWith dynamic memory method elements: ";
    int *p = ( int* )malloc(sizeof( int ) * 5); // allocating size 5 int value.
    for ( int i = 0; i < 5; i++ )
        cin >> p[ i ];

    for ( int i = 0; i < 5; i++ )
        cout << &p[ i ] << " --> " << p[ i ] << endl;

    // Solution 3: With pointer arithmetic
    cout << "\n\nWith pointer arithmetic method elements: ";
    int *p1 = ( int* )malloc(sizeof( int ) * 5); // pointer arithmetic *p1 = p1[ 0 ]
    for ( int i = 0; i < 5; i++ )
        cin >> *( p1+i );                        // *(p1+i) = p1[ 0 ],p1[ 1 ],...

    for ( int i = 0; i < 5; i++ )
        cout << ( p1+i ) << " --> " << *( p1+i ) << endl;

    return 0;
}
