// Using & and * operators..
#include <iostream>
using namespace std;
int main(){
    int a;       // a is an integer
    int *a_ptr;  // a is a pointer to an integer.

    a = 7;
    a_ptr = &a;   // The address of a is assigned to a_ptr..

    cout << "adress of int a: " << &a << endl;
    cout << "adress of variable a_ptr: " << a_ptr << endl << endl;

    cout << "value of a: " << a << endl;
    cout << "value of *a_ptr: " << *a_ptr << endl << endl;

    cout << "& and * are conjugates.. "<< endl;
    cout << "*&a_ptr: " << *&a_ptr << endl;
    cout << "&*a_ptr: " << &*a_ptr << endl;

    return 0;
}
