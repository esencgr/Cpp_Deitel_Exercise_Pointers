/* How will we can use the operators that arithmetic process and which operators can we use with pointers?t
    0: increase the pointer --> ++
    1: decrease the pointer --> --
    2: adding a integer to the pointer --> +=
    3: subtraction a integer from the pointer --> -=
    4: a pointer substraction from amother pointer --> ptr1 - ptr2

    ex:
        adresses-->   [3000]      [3004]      [3008]  ....
        vptr ----->   v[ 0 ]  //  v[ 1 ]  //  v[ 2 ]  ....
        *vptr ---->      0    //     1    //    2     ....

        vptr += 4  ->  3016 --> (3000 + 4 * 4(byte for int))
*/
#include <iostream>
using namespace std;

int main(){
    int v[ 10 ] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int *v_ptr = &v[ 0 ];                   // same mean with *v_ptr1 = v

    cout << " v_ptr : " << v_ptr << " --> " << *v_ptr << endl;

    // 0: increase the pointer --> ++
    v_ptr++;
    cout << " v_ptr++ : " << v_ptr << " --> ";
    cout <<  *v_ptr << endl;

    // 1: decrease the pointer --> --
    v_ptr--;
    cout << " v_ptr-- : " << v_ptr << " --> ";
    cout << *v_ptr << endl;

    // 2: adding a integer to the pointer --> +=
    v_ptr += 4;
    cout << " v_ptr += 4 : " << v_ptr << " --> ";
    cout << *v_ptr << endl;

    // 3: subtraction a integer from the pointer --> -=
    v_ptr -= 2;
    cout << " v_ptr -= 2 : " << v_ptr << " --> ";
    cout << *v_ptr << endl;

    // 4: a pointer substraction from amother pointer --> ptr1 - ptr2
    int *v2ptr = v_ptr + 5;
    cout << " v2ptr : " << v2ptr << " --> ";
    cout << *v2ptr << endl;

    int *vptr = v_ptr;
    cout << " vptr : " << vptr << " --> ";
    cout << *vptr << endl;

    // there is difference of this adresses total 20 bytes memory in RAM.
    // each int variable allocating 4 bytes memory in RAM.
    int x= v2ptr - vptr;           // so this eq is return the 20/4=5 bytes..
    cout << " v2ptr - vptr " << v2ptr << " - " << vptr << " --> ";
    cout << x << endl;

    return 0;
}
