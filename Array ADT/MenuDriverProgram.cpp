#include <iostream>
#include <stdlib.h>

using namespace std;

struct Array {
    int *A;
    int size;
    int length;
};

void swap(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

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
    if(index >= 0 && index <= arr->length) {
        for(int j = arr->length; j >= index; j--) {
            arr->A[j + 1] = arr->A[j];
        }

        arr->A[index] = value;

        arr->length++;

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
        if(key == arr->A[i]) {
            swap(&arr -> A[i], &arr -> A[0]);
            return i;
        }
    }

    return -1;
}

int get(struct Array *arr, int index) {
    if(index >= 0 && index < arr -> length) {
        return arr -> A[index];
    }
}

int set(struct Array *arr, int index, int newValue) {
    if(index >= 0 && index < arr -> length) {
        arr -> A[index] = newValue;
    }
}

int max(struct Array *arr) {
    int max = arr -> A[0];

    for(int i = 1; i < arr -> length; i++) {
        if(arr -> A[i] > max) {
            max = arr -> A[i];
        }
    }

    return max;
}

int min(struct Array *arr) {
    int min = arr -> A[0];

    for(int i = 1; i < arr -> length; i++) {
        if(min > arr -> A[i]) {
            min = arr -> A[i];
        }
    }

    return min;
}

int sum(struct Array *arr, int n) {
    if(n >= 0) {
        return sum(arr, n - 1) + arr -> A[n];
    } else {
        return 0;
    }
}

float avg(struct Array *arr) {
    return (float)sum(arr, arr -> length)/arr ->length;
}

void reverseArray(struct Array *arr) {
    int *B;

    B = new int[arr->size];

    for(int i = arr -> length; i > 0; i--) {
        B[arr -> length - i] = arr -> A[i - 1];
    }

    delete[] arr -> A;

    arr -> A = B;
}

void reverseArrayBySwap(struct Array *arr) {
    for(int i = 0; i < arr -> length / 2; i++) {
        swap(&(arr -> A[i]), &(arr -> A[arr -> length - 1 - i]));
    }
}

void leftShiftAndRotate(struct Array *arr) {
    int firstElement = arr -> A[0];

    for(int i = 0; i < arr -> length; i++) {
        arr -> A[i] = arr -> A[i + 1];
    }

    arr -> A[arr -> length - 1] = firstElement;
}

bool checkArrayIsSorted(struct Array *arr) {
    int i = 0;

    while(i < arr -> length - 1) {
        if(arr -> A[i] > arr -> A[i + 1]) {
            cout << "Array is NOT sorted" << endl;
            return false;
        }
        i++;
    }

    cout << "Array is sorted" << endl;
    return true;

}

int insertInAnOrderedArray(struct Array *arr, int num) {
    if(arr -> length == arr -> size) {
        cout << "Array is full!" << endl;
        return -1;
    }

    if(checkArrayIsSorted(arr)) {
        int i = arr -> length - 1;

        while(i >= 0 && arr -> A[i] > num) {
            arr -> A[i + 1] = arr -> A[i];
            i--;
        }

        arr -> A[i + 1] = num;
        arr->length++;
    } else {
        return -1;
    }

}

void interchangePositivesAndNegatives(struct Array *arr) {
    int i = 0;
    int j = arr -> length - 1;

    while(i < j) {
        while(arr -> A[i] < 0) {i++;}
        while(arr -> A[j] >= 0) {j--;}

        if(i < j) {
            swap(&arr -> A[i], &arr -> A[j]);
        }
    }
}

void merge(struct Array *x, struct Array *y) {
    if(checkArrayIsSorted(x) && checkArrayIsSorted(y)) {
        int i = 0;
        int j = 0;

        int *z;

        z = new int[x -> size + y -> size];

        int k = 0;

        while(i < x -> length && j < y -> length) {
            if(x -> A[i] < y -> A[j]) {
                z[k++] = x -> A[i++];
            } else {
                z[k++] = y -> A[j++];
            }
        }

        for(; i < x -> length; i++) {
            z[k++] = x -> A[i];
        }

        for(; j < y -> length; j++) {
            z[k++] = y -> A[j];
        }
        delete[] x -> A;
        delete[] y -> A;

        x -> length = k;
        x -> A = z;
    } else {
        cout << "One of the arrays you entered is not sorted!" << endl;
        return;
    }


}

bool searchRepeated(struct Array *arr, int key) {
    for(int i = 0; i < arr -> length; i++) {
        if(arr -> A[i] == key) {
            return true;
        }
    }

    return false;
}

struct Array unionArrays(struct Array *x, struct Array *y) {
    int i = 0;
    int j = 0;
    int k = 0;

    struct Array C;
    C.length = 0;
    C.size = x -> size + y -> size;
    C.A = new int[C.size];

    if(!checkArrayIsSorted(x) || !checkArrayIsSorted(y)) {
        for(i = 0; i < x -> length; i++) {
            C.A[k++] = x -> A[i];
            C.length++;
        }

        for(j = 0; j < y -> length; j++) {
            bool isRepeated = searchRepeated(&C, y -> A[j]);

            if(!isRepeated) {
                C.A[k++] = y -> A[j];
                C.length++;
            }
        }


    } else {
        while(i < x -> length && j < y -> length) {
            if(x -> A[i] < y -> A[j]) {
                C.A[k++] = x -> A[i++];
            } else if(y -> A[j] < x -> A[i]) {
                C.A[k++] = y -> A[j++];
            } else {
                C.A[k++] = y -> A[j++];
                i++;
            }
            C.length += 1;
        }

        while(i < x -> length){
            C.A[k++] = x->A[i++];
            C.length++;
        }

        while(j < y->length){
            C.A[k++] = y->A[j++];
            C.length++;
        }

    }

    return C;
}

struct Array intersectionArrays(struct Array *x, struct Array *y) {
    int i = 0;
    int j = 0;
    int k = 0;

    struct Array C;
    C.length = 0;
    C.size = x -> size + y -> size;
    C.A = new int[C.size];

    if(!checkArrayIsSorted(x) || !checkArrayIsSorted(y)) {
       for(i = 0; i < x -> length; i++) {
            bool isRepeated = searchRepeated(y, x -> A[i]);

            if(isRepeated) {
                C.A[k++] = x->A[i];
                C.length++;
            }
       }
    } else {
        while(i < x -> length && j < y -> length) {
            if(x -> A[i] < y -> A[j]) {
                i++;
            } else if(y -> A[j] < x -> A[i]){
                j++;
            } else {
                C.A[k++] = x->A[i];
                i++;
                j++;

                C.length++;
            }
        }
    }

    return C;
}

struct Array differenceArrays(struct Array *x, struct Array *y) {
    int i = 0;
    int j = 0;
    int k = 0;

    struct Array C;
    C.length = 0;
    C.size = x -> size + y -> size;
    C.A = new int[C.size];

    if(!checkArrayIsSorted(x) || !checkArrayIsSorted(y)) {
        for(i; i < x -> length; i++) {
            bool isRepeated = searchRepeated(y, x -> A[i]);

            if(!isRepeated) {
                C.A[k++] = x->A[i];
                C.length++;
            }
        }
    } else {
        while(i < x -> length && j < y -> length) {
            if(x -> A[i] < y -> A[j]) {
                C.A[k++] = x->A[i];
                C.length++;
                i++;
            } else if(y -> A[j] < x -> A[i]) {
                j++;
            } else {
                i++;
                j++;
            }
        }

        for(; i < x -> length; i++) {
            C.A[k++] = x -> A[i];
        }
    }

    return C;
};

int main() {
    struct Array arr1;
    int ch;
    int x, index;

    cout << "Enter size of array: ";
    scanf("%d", &arr1.size);
    arr1.A = new int[arr1.size];
    arr1.length = 0;

    cout << endl;

    do {
        cout << "Menu" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Search" << endl;
        cout << "4. Sum" << endl;
        cout << "5. Display" << endl;
        cout << "6. Exit" << endl;

        cout << "***** Enter your choice: ";
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                cout << "Enter an element and index: ";
                scanf("%d%d",&x,&index);
                Insert(&arr1, index, x);
                break;
            case 2:
                cout << "Enter index ";
                scanf("%d", &index);
                x = Remove(&arr1, index);
                cout << "Deleted element is: " << x << endl;
                break;
            case 3:
                scanf("%d",&x);
                index = LinearSearch(&arr1,x);
                printf("Element index %d",index);
                break;
            case 4:
                cout << "Sum is: " << sum(&arr1, arr1.length - 1) << endl;
                break;
            case 5:
                Display(&arr1);

        }
    } while(ch < 6);

    return 0;
}
