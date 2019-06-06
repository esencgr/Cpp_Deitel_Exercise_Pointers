// writing a function that who does strlen task.
#include <iostream>
using namespace std;

int my_strlen ( const char [] );

int main(){

    char str[ 30 ];
    cin.getline ( str, 30 );
    
    int size = my_strlen ( str );
    cout << "The string is include " <<  size << " character " << endl;

    return 0;
}

int my_strlen (const char s_ptr[] ){
     int count = 0;
     for ( int i = 0 ;  s_ptr[i] != '\0';  i++ )
         count++;

      return count;
}
