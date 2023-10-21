#include <iostream>
using namespace std;

bool compareStrings(char *A, char *B) {
    int i = 0, lengthOfA = 0;

    while (A[lengthOfA] != '\0') {
        lengthOfA++;
    }

    while ((A[i] == B[i] || abs(A[i] - B[i]) == 32) && i < lengthOfA) {
        i++;
    }

    if (A[i] == B[i] && i == lengthOfA) {
        //cout << "String A is equal to String B" << endl;
        return true;
    } else if (A[i] > B[i]) {
        //cout << "String A is greater than String B" << endl;
        return false;
    } else {
        //cout << "String B is greater than String A" << endl;
        return false;
    }
}

bool checkPalindrome(char *A) {
    char B[10];

    int i = 0, j = 0;

    while (A[i] != '\0') {
        i++;
    }

    i = i - 1;

    for(j = 0; i >= 0; j++, i--) {
        B[j] = A[i];
    }

    B[j] = '\0';


    return compareStrings(A, B);
}

bool checkPalindrome2(char *A) {
    int i = 0, j = 0;

    while(A[i] != '\0') {
        i++;
    }

    i = i - 1;

    while (j < i) {
        if (A[i] != A[j]) {
            return false;
        }

        i--;
        j++;
    }

    return true;
}

int main() {
    char str1[] = "Helloo";
    char str2[] = "hello";
    //compareStrings(str1, str2);

    char str3[] = "madam";
    char str4[] = "vitor";

    cout << str3; checkPalindrome2(str3) ? cout << " it's a palindrome" : cout <<  " it's not a palindrome";
    cout << endl;
    cout << str4; checkPalindrome2(str4) ? cout << " it's a palindrome" : cout <<  " it's not a palindrome";
    cout << endl;

    return 0;
}
