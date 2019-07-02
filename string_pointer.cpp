/*
string
*/
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

void copy( char *, const char * );
int lenght( const char * );

int main(){
    // char string1[ 80 ];
    char string2[ 80 ];
    cout << "ENTER STRING : " << endl;
    cin >> string2;

    char *string1 = (char*) malloc ( sizeof(char) * sizeof(string2) );
    copy( string1, string2 );
    cout << string1  << endl;

    cout << "LENGHT OF STRING : ";
    cout << lenght( string1 );

    return 0;
}
void copy( char *s1, const char *s2 ){
    // while ( *s1 != '\0')
    //     s1++;
    for ( ; *s1 = *s2; s1++, s2++)
        ;    // nothing
}
int lenght( const char *s ){
    int x;
    for ( x = 0; *s != '\0'; s++ )
        x++;
    return x;
}
