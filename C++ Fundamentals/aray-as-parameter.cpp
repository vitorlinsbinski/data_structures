#include <iostream>

using namespace std;

// Arrays are all passed as address of the memory
// The parameter to an array is a pointer

// A[] or *A
void fun(int A[], int n) {
    cout << sizeof(A) << endl;
    cout << sizeof(A)/sizeof(int) << endl;

    for(int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }

    cout << endl;
}

int *returnArray(int n) {
    int *Array = new int[n];
    for(int i = 0; i < n; i++) {
        Array[i] = i + 1;
    }
    return Array;
}

int main() {
    int A[] = {2,4,6,8,10};
    int n = 5;
    int sizeArray = sizeof(A)/sizeof(int);

    cout << sizeArray << endl;

    for(int x:A) {
        cout << x << " ";
    }

    cout << endl;

    fun(A, sizeArray);

    int *myNewArray = returnArray(10);


    for(int i = 0; i < 10; i++) {
        cout << myNewArray[i] << " ";
    }

    return 0;
}

