#include <iostream>

using namespace std;

int isAnagram(char *A, char *B) {
    int H[26] = {0};

    int i = 0, j = 0;

    while(A[i] != '\0') {
        H[A[i] - 97]++;
        i++;
    }

    while(B[j] != '\0') {
        H[B[j] - 97]--;

        if(H[B[j] - 97] < 0) {
            return 0;
        }

        j++;
    }

    return 1;
}

int main() {
    char A[] = "verbose";
    char B[] = "observe";

    int result = isAnagram(A, B);

    cout << result;

    return 0;
}
