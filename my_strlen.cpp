// writing a function that who does strlen task.
#include <iostream>
#include <string>
using namespace std;

int my_strlen ( const char* );
int my_strlen2 ( char * );
int main(){

    char str[ 30 ];
    cin.getline ( str, 30 );

    int size = my_strlen ( str );
    cout << "1.The string is include " <<  size << " character " << endl;

    int size1 = my_strlen2 ( str );
    cout << "2.The string is include " <<  size1 << " character " << endl;


    return 0;
}

// In ths function, s_ptr is a pointer that defined a character constant.
// The characters can't changes using by s_ptr. ( So, s_ptr is only a readable pointer.)
int my_strlen ( const char *s_ptr ){         // the function hasn't got first variable assignment.
     int count = 0;
     for ( ;  *s_ptr != '\0';  *s_ptr++ )
         count++;

      return count;
}

int my_strlen2( char *str ){
    int count = 0;
    while ( *str++ != '\0' ){
        count++;
    }
    return count;
}
