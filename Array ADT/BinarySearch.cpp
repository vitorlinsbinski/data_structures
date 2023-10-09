#include <iostream>

using namespace std;

int arraySize = 40;


int BinarySearch(int *arr, int key, int l, int h) {
    if(l > h) {
        cout << key << " was not found in the array..." << endl;
        return -1;
    }

    int m = (l + h) / 2;

    if(key == arr[m]) {
        return m;
    }

    if(key > arr[m]) {
        return BinarySearch(arr, key, m + 1, h);
    } else if(key < arr[m]) {
        return BinarySearch(arr, key, l, m - 1);
    }
}

int main() {
    int *A;

    A = new int[arraySize];

    for(int i = 0; i < arraySize; i++) {
        A[i] = (i + 1) * 2;
    }


    for(int i = 0; i < arraySize; i++) {
        cout << A[i] <<  " ";
    }

    cout << endl;
    int key = 80;

    int result = BinarySearch(A, key, 0, arraySize - 1);

    cout << result << endl;
}
