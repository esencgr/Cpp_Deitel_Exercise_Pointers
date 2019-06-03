// writing a function that who does strlen task.
#include <iostream>
#include <string>
using namespace std;

int my_strlen ( const char * );

int main(){

    // string str;
    // cin >> str;
    // //cout << "str :" << str << endl;

    char str[ 30 ];
    cin.getline ( str, 30 );
    int size = my_strlen ( str );
    cout << "The string is include " <<  size << "character " << endl;

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
