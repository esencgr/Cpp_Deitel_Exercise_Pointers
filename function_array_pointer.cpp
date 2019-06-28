/*
The pointer array that showing function.
*/
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void func1 ( int );
void func2( int );
void func3( int );

int main(){
    /*
       This defination mean is : A function that takes int as an argument, and
       three pointer array showing that non_return function.
       The names of these three functions are assigned to the array.
    */

    void ( *func_arr[ 3 ] )( int ) = { func1, func2, func3 };
    int choise;

    do{
        cout << "\n make your choise between 0-2 numbers for function and enter 3 for quit : ";
        cin >> choise;
            if ( choise == 3 )
                break;
        ( *func_arr[ choise ] )( choise );
    } while ( choise >= 0 && choise < 3 );

    cout << " quit.. " << '\n';
    return 0;
}

void func1( int a ){
    cout << " your choise is " << a << " and function 1 called " << endl;
}

void func2( int b ){
    cout << " your choise is " << b << " and function 1 called " << endl;
}

void func3( int c ){
    cout << " your choise is " << c << " and function 1 called " << endl;
}
