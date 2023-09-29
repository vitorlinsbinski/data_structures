#include <iostream>
#include <stdlib.h>

using namespace std;

struct Array {
    int *A;
    int size;
    int length;
};

void Display(struct Array *arr) {
    int i;

    cout << "Elements are: " << endl;

    for(i = 0; i < arr->length; i++) {
        cout << arr->A[i] << " ";
    }

    cout << endl;
}

void Append(struct Array *arr, int value) {
    if(arr -> length < arr -> size) {
        arr->A[arr->length] = value;
        arr -> length = arr -> length + 1;

        return;
    } else {
        cout << "Array is full!" << endl;
        return;
    }

}

void Insert(struct Array *arr, int index, int value) {
    if(index >= 0 && arr->length < arr->size) {
        for(int j = arr->length; j >= index; j--) {
            arr->A[j + 1] = arr->A[j];
        }

        arr->A[index] = value;

        arr->length = arr->length + 1;

        return;
    } else {
        cout << "Array is full!" << endl;
        return ;
    }
}

int Remove(struct Array *arr, int index) {
    int x = 0;

    if(arr -> length > 0 && index >= 0 && index < arr -> length) {
        x = arr -> A[index];
        for(int i = index; i < arr -> length; i++) {
            arr -> A[i] = arr -> A[i + 1];
        }
        arr -> length = arr -> length - 1;

        return x;
    }

    return 0;
}

int LinearSearch(struct Array *arr, int key) {
    if(arr -> length < 0) {
        cout << "Array has no elements..." << endl;
        return -1;
    }

    for(int i = 0; i < arr -> length; i++) {
        if(arr->A[i] == key) {
            return i;
        }
    }

    return -1;
}

int main() {
    struct Array arr;
    int n, i;
    cout << "Enter size of an array" << endl;
    scanf("%d", &arr.size);
    arr.A = new int[arr.size];
    arr.length = 0;

    cout << "Enter number of numbers: " << endl;
    scanf("%d", &n);

    cout << "Enter all elements" << endl;
    for(i = 0; i < n; i++) {
        scanf("%d", &arr.A[i]);
    }
    arr.length = n;

    Display(&arr);

    cout << "Append Operation: " << endl;
    Append(&arr, 123);
    Display(&arr);

    cout << "Insert Operation: " << endl;
    Insert(&arr, 0, 888);
    Display(&arr);

    cout << "Remove Operation: " << endl;
    cout << Remove(&arr, 5) << endl;
    Display(&arr);

    cout << "Linear Search: " << endl;
    int indexSearch = LinearSearch(&arr, 2);
    if(indexSearch >= 0) {
        cout << "Element was found in index: " << indexSearch << endl;
    } else {
        cout << "Element was not found..." << endl;
    }

    return 0;
}
