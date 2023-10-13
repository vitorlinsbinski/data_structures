#include <iostream>

using namespace std;

template<class T>

class Array {
private:
    T* A;
    int size;
    int length;
public:
    Array(int _size) {
        size = _size;
        length = 0;
        A = new T[size];
    }

    void swap(T *x, T *y) {
        T temp;
        temp = *x;
        *x = *y;
        *y = temp;
    }

    void Append(T value) {
        if(length < size) {
            A[length] = value;
            length++;

            return;
        } else {
            cout << "Array is full!" << endl;
            return;
        }
    }

    void Insert(int index, T value) {
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

    T Remove(int index) {
        T x = 0;

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

    T LinearSearch(T key) {
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

    T get(int index) {
        if(index >= 0 && index < length) {
            return A[index];
        }
    }

    T set(int index, int newValue) {
        if(index >= 0 && index < length) {
            A[index] = newValue;
        }
    }

    T max() {
        T max = A[0];

        for(int i = 1; i < length; i++) {
            if(A[i] > max) {
                max = A[i];
            }
        }

        return max;
    }

    T min() {
        T min = A[0];

        for(int i = 1; i <  length; i++) {
            if(min > A[i]) {
                min =  A[i];
            }
        }

        return min;
    }


    T sum(int n) {
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
        T *B;

        B = new T[size];

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
        T firstElement =  A[0];

        for(int i = 0; i <  length; i++) {
             A[i] =  A[i + 1];
        }

         A[ length - 1] = firstElement;
    }

    bool checkArrayIsSorted(T *arr, int length) {
        for (int i = 0; i < length - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                return false;
            }
        }
        return true;
    }

    T insertInAnOrderedArray(T num) {
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

            z = new T[x.size + y.size];

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

    bool searchRepeated(T key) {
        for(int i = 0; i <  length; i++) {
            if( A[i] == key) {
                return true;
            }
        }

        return false;
    }

    Array unionArrays(const Array y) {
        int size = length + y.length;

        Array<T> result(size);

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

        Array<T> result(size);

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

        Array<T> result(size);

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

    void getMissingElements() {
        int diff = A[0];

        for(int i = 0; i < length; i++) {
            while(diff != A[i] - i) {
                cout << i + diff << " ";
                diff++;
            }

        }

        cout <<  "are missing" << endl;
    }

    void getMissingElements2() {
        T h = A[length - 1];

        T hashArray[h] = {0};

        for(int i = 0; i < length; i++) {
            hashArray[A[i]]++;
        }

        for(int j = 0; j < h; j++) {
            if(hashArray[j] == 0) {
                cout << j << " ";
            }
        }

        cout << "are missing" << endl;
    }

    void getDuplicateElementsSorted() {
        int countDuplicated = 0;

        for(int i = 0; i < length; i++) {
            if(A[i] == A[i + 1]) {
                countDuplicated = i + 1;
                while(A[countDuplicated] == A[i]) {
                    countDuplicated++;
                }

                cout << A[i] << " is appearing " << countDuplicated - i << " times" << endl;
                i = countDuplicated - 1;
            }
        }
    }

    void getDuplicateSortedUsingHash() {
        T h = A[length - 1];

        T hashArray[h + 1] = {0};

        for(int i = 0; i < length; i++) {
            hashArray[A[i]] += 1;
        }

        for(int j = 0; j <= h; j++) {
            if(hashArray[j] > 1) {
                cout << j << " is appearing " << hashArray[j] << " times" << endl;
            }
        }
    }

    void getDuplicateUnsorted() {
        int count = 1;

        for(int i = 0; i < length; i++) {
            if(A[i] != -1) {
                for(int j = i + 1; j < length; j++) {
                    if(A[i] == A[j]) {
                        count++;
                        A[j] = -1;
                    }
                }
            }

            if(count >  1) {
                cout << A[i] << " is repeating " << count << " times" << endl;
            }

            count = 1;

        }
    }

    void getDuplicateUnsortedByHash() {
        T h = max();

        T hashArray[h + 1] = {0};

        for(int i = 0; i < length; i++) {
            hashArray[A[i]] += 1;
        }

        for(int j = 0; j <= h; j++) {
            if(hashArray[j] > 1) {
                cout << j << " is repeating " << hashArray[j] << " times" << endl;
            }
        }
    }

    void getSumEqualTo(T k) {
        for(int i = 0; i < length - 1; i++) {
            for(int j = 0; j < length; j++) {
                if(A[i] + A[j] == k) {
                    printf("%d + %d = %d\n", A[i], A[j], k);
                }
            }
        }
    }

    void getSumEqualToByHash(T k) {
        T h = max();

        T hashArray[h + 1] = {0};

        int b = 0;

        for(int i = 0; i < length; i++) {
            b = k - A[i];

            if(b >= 0 && hashArray[b] != 0) {
                printf("%d + %d = %d\n", A[i], b, k);
            }

            hashArray[A[i]]++;
        }
    }

    void getSumEqualToSorted(T k) {
        int i = 0, j = length - 1;

        while(i < j) {
            if(A[i] + A[j] > k) {
                j--;
            } else if(A[i] + A[j] < k) {
                i++;
            } else {
                printf("%d + %d = %d\n", A[i], A[j], k);
                i++;
                j--;
            }
        }
    }

    void getMaxAndMin() {
        T max = A[0];
        T min = A[0];

        for(int i = 1; i < length; i++) {
            if(A[i] < min) {
                min = A[i];
            } else if(A[i] > max) {
                max = A[i];
            }
        }

        cout << "max: " << max << endl;
        cout << "min: " << min << endl;
    }


    ~Array() {
        delete[] A;
    }
};

int main() {
    Array<int> arr1(10);
    Array<int> arr2(10);
    Array<int> arr3(10);
    Array<int> arr4(10);
    Array<int> arr5(10);

    arr1.Append(6);
    arr1.Append(7);
    arr1.Append(8);
    arr1.Append(9);
    arr1.Append(11);
    arr1.Append(12);
    arr1.Append(15);
    arr1.Append(16);
    arr1.Append(17);
    arr1.Append(18);
    arr1.Append(19);

    arr2.Append(3);
    arr2.Append(7);
    arr2.Append(4);
    arr2.Append(9);
    arr2.Append(6);
    arr2.Append(1);
    arr2.Append(11);
    arr2.Append(2);
    arr2.Append(10);

    arr3.Append(3);
    arr3.Append(6);
    arr3.Append(8);
    arr3.Append(8);
    arr3.Append(10);
    arr3.Append(12);
    arr3.Append(15);
    arr3.Append(15);
    arr3.Append(15);
    arr3.Append(20);


    arr4.Append(6);
    arr4.Append(3);
    arr4.Append(8);
    arr4.Append(10);
    arr4.Append(16);
    arr4.Append(7);
    arr4.Append(5);
    arr4.Append(2);
    arr4.Append(9);
    arr4.Append(14);

    arr5.Append(1);
    arr5.Append(3);
    arr5.Append(4);
    arr5.Append(5);
    arr5.Append(6);
    arr5.Append(8);
    arr5.Append(9);
    arr5.Append(10);
    arr5.Append(12);
    arr5.Append(14);

    arr1.Display();
    arr1.getMissingElements();

    arr1.Display();
    arr2.getMissingElements2();

    arr3.Display();
    arr3.getDuplicateSortedUsingHash();
    //arr2.Display();

    arr4.Display();
    arr4.getDuplicateUnsortedByHash();

    arr4.getSumEqualToByHash(10);

    arr5.Display();
    arr5.getSumEqualToSorted(10);
    arr5.getMaxAndMin();

    //cout << "Sum of the elements of arr1 is: " << arr1.sum(9) << endl;

    //Array<int> result = arr1.unionArrays(arr2);
    //result.Display();

    return 0;
}
