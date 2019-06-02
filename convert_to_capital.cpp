// Using flexible data and flexible pointers in functions.
#include <iostream>
#include <string>
using namespace std;

void conv_cap ( char * );

int main(){

    // string str;
    // getline ( cin, str );
    // cout << "str :" << str << endl;

    char string[ 30 ];
    cin.getline ( string, 30 );
    cout << "The string is before unconverted :" << string << endl;
    conv_cap ( string );
    cout << "The string is after converted :" << string << endl;

    return 0;
}

void conv_cap ( char *s_ptr ){
    while ( *s_ptr != '\0' ){
        if (islower ( *s_ptr ))         // each character is being test and if it is lower case convert to upper case.
           *s_ptr = toupper ( *s_ptr ); // convert to capital using toupper func.
        ++s_ptr;                        // passing the other character
    }
}
