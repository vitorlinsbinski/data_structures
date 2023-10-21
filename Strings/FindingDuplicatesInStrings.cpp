#include <iostream>

using namespace std;

int getMaximumASCIICode(char *A) {
    int max = 0;
    int i = 0;

    while(A[i] != '\0') {
        if(A[i] > max) {
            max = A[i];
        }

        i++;
    }

    return max;
}

void findDuplicates1(char *A) {
    int size = 0;
    int count = 1;

    while(A[size] != '\0') {
        size++;
    }

    for(int i = 0; i <= size; i++) {
        for(int j = i + 1; j < size; j++) {
            if(A[i] == A[j] && A[j] != '0') {
                count++;
                A[j] = '0';
            }
        }

        if(count > 1) {
            cout << A[i] << " is duplicate " << count << " times" << endl;
        }

        count = 1;
    }
}

void findingDuplicatesUsingHash(char *A) {
    int H[26] = {0};

    int i = 0;

    while(A[i] != '\0') {
        H[A[i] - 97]++;
        i++;
    }

    for(int j = 0; j < 26; j++) {
        if(H[j] > 1) {
            printf("%c is repeating %d times\n", j + 97, H[j]);
        }
    }
}

void findingDuplicatesUsingBitwiseOperation(char *A) {
    int H = 0, x = 0;

    for(int i = 0; A[i] != '\0'; i++) {
        x = 1;

        x = x << (A[i] - 97);

        if((x & H) > 0) {
            printf("%c is duplicate\n", A[i]);
        } else {
            H = x | H;
        }
    }
}

int main() {
    char str[] = "finding";

    cout << str << endl;

    findingDuplicatesUsingBitwiseOperation(str);
}
