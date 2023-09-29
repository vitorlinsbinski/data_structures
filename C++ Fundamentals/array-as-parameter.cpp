#include <iostream>

using namespace std;

// int A[] is a pointer to an array, it's not the array properly
// A [address] -------------> A [2][4][6][8][10]
void fun(int A[], int n) {
    int i;
    for(i = 0; i < n; i++) {
        cout << A[i] << endl;
    }

    A[0] = 25;
}

int* fun1(int n) {
    int* p;
    p = new int[n];

    return p;
}

int main() {
    int A[5] = {2,4,6,8,10};
    fun(A, 5);

    cout << endl;

    for(int i = 0; i < 5; i++) {
        cout << A[i] << endl;
    }

    cout << endl;

    int* B;
    B = fun1(5);

    B[0] = 1;
    B[1] = 2;
    B[2] = 3;
    B[3] = 4;
    B[4] = 5;

    for(int i = 0; i < 5; i++) {
        cout << B[i] << endl;
    }

    return 0;
}
