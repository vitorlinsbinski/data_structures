#include <iostream>

using namespace std;

class Array {
private:
    int *A;
    int size;
    int length;
public:
    Array(int _size) {
        size = _size;
        length = 0;
        A = new int[size];
    }

    void swap(int *x, int *y) {
        int temp;
        temp = *x;
        *x = *y;
        *y = temp;
    }

    void Append(int value) {
        if(length < size) {
            A[length] = value;
            length++;

            return;
        } else {
            cout << "Array is full!" << endl;
            return;
        }
    }

    void Insert(int index, int value) {
        if(index >= 0 && length < size) {
            for(int j = length; j >= index; j--) {
                A[j + 1] = A[j];
            }

            A[index] = value;

            length++;

            return;
        } else {
            cout << "Array is full!" << endl;
            return ;
        }
    }

    int Remove(int index) {
        int x = 0;

        if(length > 0 && index >= 0 && index < length) {
            x = A[index];
            for(int i = index; i < length; i++) {
                A[i] = A[i + 1];
            }
            length++;

            return x;
        }

        return -1;
    }

    int LinearSearch(int key) {
        if(length < 0) {
            cout << "Array has no elements..." << endl;
            return -1;
        }

        for(int i = 0; i < length; i++) {
            if(key == A[i]) {
                swap(&A[i], &A[0]);
                return i;
            }
        }

        return -1;
    }

    void Display() {
        int i;

        cout << "Elements are: " << endl;

        for(i = 0; i < length; i++) {
            cout << A[i] << " ";
        }

        cout << endl;
    }

    int get(int index) {
        if(index >= 0 && index < length) {
            return A[index];
        }
    }

    int set(int index, int newValue) {
        if(index >= 0 && index < length) {
            A[index] = newValue;
        }
    }

    int max() {
        int max = A[0];

        for(int i = 1; i < length; i++) {
            if(A[i] > max) {
                max = A[i];
            }
        }

        return max;
    }

    int min() {
        int min = A[0];

        for(int i = 1; i <  length; i++) {
            if(min > A[i]) {
                min =  A[i];
            }
        }

        return min;
    }

    int sum(int n) {
        if(n >= 0) {
            return sum(n - 1) +  A[n];
        } else {
            return 0;
        }
    }

    float avg() {
        return (float)sum(length)/length;
    }

    void reverseArray() {
        int *B;

        B = new int[size];

        for(int i =  length; i > 0; i--) {
            B[ length - i] =  A[i - 1];
        }

        delete[]  A;

         A = B;
    }

    void reverseArrayBySwap() {
        for(int i = 0; i <  length / 2; i++) {
            swap(&( A[i]), &( A[ length - 1 - i]));
        }
    }

    void leftShiftAndRotate() {
        int firstElement =  A[0];

        for(int i = 0; i <  length; i++) {
             A[i] =  A[i + 1];
        }

         A[ length - 1] = firstElement;
    }

    bool checkArrayIsSorted(int *arr, int length) {
        for (int i = 0; i < length - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                return false;
            }
        }
        return true;
    }

    int insertInAnOrderedArray(int num) {
        if( length ==  size) {
            cout << "Array is full!" << endl;
            return -1;
        }

        if(checkArrayIsSorted(A, length)) {
            int i =  length - 1;

            while(i >= 0 &&  A[i] > num) {
                 A[i + 1] =  A[i];
                i--;
            }

             A[i + 1] = num;
             length++;
        } else {
            return -1;
        }

    }

    void interchangePositivesAndNegatives() {
        int i = 0;
        int j =  length - 1;

        while(i < j) {
            while( A[i] < 0) {i++;}
            while( A[j] >= 0) {j--;}

            if(i < j) {
                swap(& A[i], & A[j]);
            }
        }
    }

    void merge(Array x, Array y) {
        if(checkArrayIsSorted(x.A, x.length) && checkArrayIsSorted(y.A, y.length)) {
            int i = 0;
            int j = 0;

            int *z;

            z = new int[x.size + y.size];

            int k = 0;

            while(i < x.length && j < y.length) {
                if(x.A[i] < y.A[j]) {
                    z[k++] = x.A[i++];
                } else {
                    z[k++] = y.A[j++];
                }
            }

            for(; i < x.length; i++) {
                z[k++] = x.A[i];
            }

            for(; j < y.length; j++) {
                z[k++] = y.A[j];
            }
            delete[] x.A;
            delete[] y.A;

            x.length = k;
            x.A = z;
        } else {
            cout << "One of the arrays you entered is not sorted!" << endl;
            return;
        }


    }

    bool searchRepeated(int key) {
        for(int i = 0; i <  length; i++) {
            if( A[i] == key) {
                return true;
            }
        }

        return false;
    }

    Array unionArrays(const Array y) {
        int size = length + y.length;

        Array result(size);

        int i = 0, j = 0, k = 0;

        while (i < length && j < y.length) {
            if (A[i] < y.A[j]) {
                result.A[k++] = A[i++];
            } else if (y.A[j] < A[i]) {
                result.A[k++] = y.A[j++];
            } else {
                result.A[k++] = A[i++];
                j++;
            }
            result.length++;
        }

        while (i < length) {
            result.A[k++] = A[i++];
            result.length++;
        }

        while (j < y.length) {
            result.A[k++] = y.A[j++];
            result.length++;
        }

        return result;
    }

    Array intersectionArrays(const Array y) {
        int size = (length < y.length) ? length : y.length;

        Array result(size);

        int i = 0, j = 0, k = 0;

        while (i < length && j < y.length) {
            if (A[i] < y.A[j]) {
                i++;
            } else if (y.A[j] < A[i]) {
                j++;
            } else {
                result.A[k++] = A[i];
                i++;
                j++;
                result.length++;
            }
        }

        return result;
    }


    Array differenceArrays(const Array y) {
        int size = length;

        Array result(size);

        int i = 0, j = 0, k = 0;

        while (i < length && j < y.length) {
            if (A[i] < y.A[j]) {
                result.A[k++] = A[i++];
                result.length++;
            } else if (y.A[j] < A[i]) {
                j++;
            } else {
                i++;
                j++;
            }
        }

        while (i < length) {
            result.A[k++] = A[i++];
            result.length++;
        }

        return result;
    }

    ~Array() {
        delete[] A;
    }
};

int main() {
    Array arr1(10);
    Array arr2(10);

    arr1.Append(1);
    arr1.Append(2);
    arr1.Append(3);
    arr1.Append(4);
    arr1.Append(5);

    arr2.Append(1);
    arr2.Append(4);
    arr2.Append(6);
    arr2.Append(7);
    arr2.Append(9);

    arr1.Display();
    arr2.Display();

    Array result = arr1.unionArrays(arr2);
    result.Display();

    return 0;
}
