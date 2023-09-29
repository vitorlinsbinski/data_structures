// pointer is an address variable
// that means storing address of data
// it's used to access the data indirectly
// why do we need pointers?
// A: we use pointers to access resources that are external from our stack/code section, like the heap main memory and external devices or resources
// For sample: access the internet, a mouse, a keyboard, a monitor, etc.

#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
    int a = 10;
    // declaring a pointer called 'p'
    int *p;
    // initializing 'p' as address of 'a'
    p = &a;

    // print the value the variable 'a' store
    cout << a << endl;
    // print the address of the pointer 'p', that points to 'a'
    cout << p << endl;
    // print the value that 'p' points, that means the value of 'a'F
    cout << *p << endl;

    // ## In C:
    int *p1;

    // assign the memory allocation for int pointer 'p1', that is an array of 5 int elements
    // we need to declare before malloc function what type of pointer is. In this case, it's a int pointer: (int *)
    p1 = (int *)malloc(5*sizeof(int));

    // ## In C++:
    int *p2;

    p2 = new int[5];

    int A[5] = {2,4,6,8,10};
    int *p3;
    p3 = A;

    for(int i = 0; i < sizeof(A)/sizeof(A[0]); i++) {
        cout << &p3[i] << endl;
    }

    cout << "Address of the array: " << p3 << endl;

    int *p4;
    p4 = new int[5];
    p4[0] = 1;
    p4[1] = 2;
    p4[2] = 3;
    p4[3] = 4;
    p4[4] = 5;

    for(int i = 0; i < 5; i++) {
        cout << p4[i] << endl;
    }

    delete[] p2;
    delete[] p4;

    // pointers take the same amount of memory: 8 bytes

    return 0;
}
