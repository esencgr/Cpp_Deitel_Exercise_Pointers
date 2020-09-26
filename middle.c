#include <stdio.h>

// int *find_mid ( int arr[], int n ){
//     return &arr[ n/2 ];
// }

int main(){
    int a[] = { 1,2,3,4,5 };
    int n = sizeof( a ) / sizeof( a[ 0 ] );
    // int *mid = find_mid( a, n );
    // printf("%d\n", *mid );

    int sum = 0, *p;
    for ( p = a; p < a+n ; p++)
        sum += *p;
    printf("%d\n", sum );

    for ( p = &a[ 0 ]; p < &a[ n ] ; p++)
        sum += *p;
    printf("%d\n", sum );
  return 0;
}
