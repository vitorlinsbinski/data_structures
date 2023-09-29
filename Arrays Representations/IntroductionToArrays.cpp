#include <iostream>

using namespace std;

int main() {
    int A[5];
    int B[5] = {1,2,3,4,5};
    int C[10] = {2,4,6};
    int D[5] = {0};
    int E[] = {1,2,3,4,5,6};

    int i;

    // Garbage values
    for(i = 0; i < sizeof(A)/sizeof(A[0]); i++) {
        cout << A[i] << " ";
    }

    cout << endl;

    // Print all the elements of B
    for(i = 0; i < sizeof(B)/sizeof(B[0]); i++) {
        cout << B[i] << " ";
    }

    cout << endl;

    // It will be printed only "0" after the third element
    for(i = 0; i < sizeof(C)/sizeof(C[0]); i++) {
        cout << C[i] << " ";
    }

    cout << endl;


    // It will be printed only "0" in each position of the array
    for(i = 0; i < sizeof(D)/sizeof(D[0]); i++) {
        cout << D[i] << " ";
    }

    cout << endl;

    // Print all the elements of E
    for(i = 0; i < sizeof(E)/sizeof(E[0]); i++) {
        cout << E[i] << " ";
    }

    cout << endl;

    // Address in the memory of each element in array E will be printed
    // Note that each address is separated from each other by a number of bytes equal to the size of each element in the array
    for(i = 0; i < sizeof(E)/sizeof(E[0]); i++) {
        cout << &E[i] << " ";
    }

    return 0;
}
