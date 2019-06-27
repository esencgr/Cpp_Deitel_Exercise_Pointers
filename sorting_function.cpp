/*
Using the pointer showing a sorting function having a lot of purpose.
*/
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void rand_array ( int *, const int );
void print( int *, const int );
void bubble( int *, const int, int(*)(int, int) );
int increasing( int, int );
int decreasing( int, int );

int main(){

    srand(time ( NULL ));
    int choise;
    const int SIZE = 10;

    int array[ SIZE ];
    cout << " Original order : ";
    rand_array ( array, SIZE );
    print ( array, SIZE );

    cout << "\n\n Enter your choice 1(increase) - 2(decrease) : ";
    cin >> choise;

    switch ( choise ){
        case 1 :
            cout << "\n Increasing order : ";
            bubble( array, SIZE, increasing );
            print ( array, SIZE );
            break;
        case 2 :
            cout << "\n Decreasing order : ";
            bubble( array, SIZE, decreasing );
            print ( array, SIZE );
            break;
    }

    return 0;
}
void rand_array ( int *array, const int SIZE ){
    for ( int i = 0;  i < SIZE;  i++)
        array[ i ] = 1 + rand( ) % 100;
}
void print( int *array, const int SIZE ){
    for ( int i = 0;  i < SIZE;  i++)
        cout << array[ i ] << " " ;
}
void bubble( int *array, const int SIZE, int (*compare)( int, int ) ){
    void change( int *, int * );
    for ( int tour = 0;  tour < SIZE;  tour++){
        for ( int i = 0;  i < SIZE - 1;  i++ ){
            if ( (*compare)( array[ i ], array [ i + 1 ] ) )
               change( &array[ i ], &array [ i + 1 ] );
        }
    }
}

void change( int *e1_ptr, int *e2_ptr ){
    int temp;
    temp = *e1_ptr;
    *e1_ptr = *e2_ptr;
    *e2_ptr = temp;
}

int increasing( int e1, int e2 ){
    return e1 > e2;               // if a is greater than b, replaced a and b.
}

int decreasing( int e1, int e2 ){
    return e1 < e2;               // if b is greater than a, replaced a and b.
}
