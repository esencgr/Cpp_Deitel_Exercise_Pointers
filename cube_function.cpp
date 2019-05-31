// Creating a number's cube function using invocation by value or by reference.
#include <iostream>
using namespace std;

int cube_value ( int );
void cube_reference ( int * );

int main (){
    int number = 5;
    cout << "The number is : " << number << endl;

    cout << "Invocation by value : ";
    number = cube_value ( number );
    cout << number << endl;

    cout << "Invocation by reference : ";
    cube_reference ( &number );
    cout << number << endl;

    return 0;
}

int cube_value ( int x ){              // call by value
    return x * x * x;                  // local "x" variable's cube
}

void cube_reference ( int *x_ptr ){    // call by reference
    (*x_ptr) * (*x_ptr) * (*x_ptr);    // "number" variable's cube in main function
}
