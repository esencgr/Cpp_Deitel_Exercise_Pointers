//using of functions with the pointers.
#include <iostream>
using namespace std;

// scope of variable..
int call_value ( int x ){         // call by value
    x = 30;                       // this x value is only defined between of this brackets.
}
int call_reference ( int *x, int *y, int *z ){    // call by reference
    *x = 30;
    *y = 40;                      // this x, y, z value is defined when this pointers are called.
    *z = 20;
}

int main (){

    int a = 10, b = 20, c = 30;   // memory location is necessary for not getting of segmentation fault.
    int *p = &a;
    int *q = &b;
    int *r = &c;

    // this function means is basically that variables copy.
    call_value ( a );             // this code return 10.
    cout << a << endl;            // a and x are different variable and this ram memory adresses are different.

    // it is possible that a lot of returned value in functions with call by reference.
    call_reference ( p, q, r );
    cout << *p << *q << *r << endl;

    return 0;
}
