// Creating a number's cube function using invocation by value or by reference.
#include <iostream>
using namespace std;

int cube_value ( int );
void cube_reference ( int *, int * );

int main (){
    int number = 5, number2 = 10, number3 = 100;
    cout << "The number is : " << number << endl;

    // This function can return only one value.
    cout << "Invocation by value ( 5^3 ): ";
    number = cube_value ( number );
    cout << number << endl;

    // This function can return one or more value because process is actualized in the different address.
    // So it is possible that return more than one value in a function with pointers.
    cout << "Invocation by reference ( 10^3 & 100^3 ): ";
    cube_reference ( &number2, &number3 );
    cout << number2 << " " << number3 << endl;

    return 0;
}

int cube_value ( int x ){              // call by value
    return x * x * x;                  // local "x" variable's cube
}

void cube_reference ( int *x_ptr, int *y_ptr){    // call by reference
    *x_ptr = (*x_ptr) * (*x_ptr) * (*x_ptr);      // "number2" variable's cube in main function
    *y_ptr = (*y_ptr) * (*y_ptr) * (*y_ptr);
}
