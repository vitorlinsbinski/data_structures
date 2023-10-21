#include <iostream>

using namespace std;

void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;

}

void reverseString(char *A, char *B) {
    int i, j;

    for(i = 0; A[i] != '\0'; i++) {

    }

    i = i - 1;

    for(j = 0; i >= 0; j++, i--) {
        B[j] = A[i];
    }

    B[j] = '\0';
}

void reverseStringBySwapping(char *A) {
    int i, j;

    for(j = 0; A[j] != '\0'; j++) {

    }

    j = j - 1;

    i = 0;

    while(i < j) {
        swap(A[i], A[j]);
        i++;
        j--;
    }

}

int main() {
    char A[] = "python";
    char B[7];

    cout << A << endl;

    reverseString(A, B);

    cout << B << endl;

    reverseStringBySwapping(A);
    cout << A << endl;

    reverseStringBySwapping(A);
    cout << A << endl;

    return 0;
}
