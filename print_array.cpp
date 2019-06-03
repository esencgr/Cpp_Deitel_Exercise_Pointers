// Using fixed data and flexible pointers in functions.
#include <iostream>
#include <string>
using namespace std;

void print_arr ( const char * );

int main(){

    // string str;
    // getline ( cin, str );
    // cout << "str :" << str << endl;

    char string[ 30 ];
    cin.getline ( string, 30 );
    print_arr ( string );
    cout << "The string is printing :" << string << endl;

    return 0;
}

// In ths function, s_ptr is a pointer that defined a character constant.
// The characters can't changes using by s_ptr. ( So, s_ptr is only a readable pointer.)
void conv_cap ( const char *s_ptr ){         // the function hasn't got first variable assignment.
     for ( ;  *s_ptr != '\0';  *s_ptr++ ){
         cout << *s_ptr << endl;
     }
}
