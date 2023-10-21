#include <iostream>

using namespace std;

void perm(char *S, int k) {
    static int A[10] = {};
    static char R[10]={};
    int i;

    if(S[k] == '\0') {
        R[k] = '\0';

        cout << R << endl;
    } else {
        for(i = 0; S[i] != '\0'; i++) {
            if(A[i] == 0) {
                R[k] = S[i];
                A[i] = 1;
                perm(S, k + 1);
                A[i] = 0;
            }
        }
    }

}

void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

void permBySwapping(char *S, int l, int h) {
    int i;

    if(l == h) {
        cout << S << endl;
    } else {
        for(i = l; i <= h; i++) {
            swap(S[l], S[i]);
            permBySwapping(S, l + 1, h);
            swap(S[l], S[i]);
        }
    }
}

int main() {
    char A[] = "ABC";
    perm(A, 0);
    cout << endl;
    permBySwapping(A, 0, 2);
    return 0;
}
