// Copying a string using array notation and pointer notation..
#include <iostream>
#include <stdlib.h>
using namespace std;

void copy1( char*, const char*);
void copy2( char[], const char[]);

int main(){

    const char *string2 = "HELLO USER";
    char *string1 = (char*) malloc ( sizeof(char) * sizeof(*string2) );

    const char string4[] = "CGR ESEN";
    char string3[ sizeof(string4) ];

    copy1( string1, string2 );
    cout << "string1 : " << string1 << endl;

    copy2( string3, string4 );
    cout << "string3 : " << string3;

    return 0;
}
// copying the s1 to s2 with pointer notation
void copy1( char *s1, const char *s2){
     for ( ; ( *s1 = *s2 ) != '\0'; s1++ ,s2++)
         ;
}
// copying the s1 to s2 with array notation
void copy2( char s1[], const char s2[] ){
     for ( int i = 0; (s1[ i ] = s2[ i ]) != '\0';  i++)
         ;
}
/*
void copy1( char *s1, const char *s2){
   for ( int i = 0; (s2[ i ]) != '\0';  i++)
       s1[ i ] = s2[ i ];
}
void copy2( char *s1, const char *s2 ){
   for ( ; ( *s2 ) != '\0'; s1++ ,s2++)
       *s1 = *s2;
}*/
