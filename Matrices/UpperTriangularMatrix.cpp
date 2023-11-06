#include <iostream>

using namespace std;

class UpperTriangularMatrix {
private:
    int *A;
    int n;

public:
    UpperTriangularMatrix(int n) {
        this -> n = n;
        A = new int[(n*(n + 1)) / 2];
    }

    void rowModeSet(int i, int j, int x) {
        if(i <= j) {
            A[(n*(i - 1) - ((i - 2)*(i - 1))/2) + j - i] = x;
        }
    }

    int rowModeGet(int i, int j) {
        if(i <= j) {
            return A[(n*(i - 1) - ((i - 2) - (i - 1))/2) + j - i];
        } else {
            return 0;
        }
    }

    void columnModeSet(int i, int j, int x) {
        if(i <= j) {
            A[j*(j-1)/2 + i - 1] = x;
        }
    }

    int columnModeGet(int i, int j) {
        if(i <= j) {
            return A[j*(j-1)/2 + i - 1];
        } else {
            return 0;
        }
    }


    void display() {
        int i, j;

        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                if(i <= j) {
                    cout << A[i] << " ";
                } else {
                    cout << "0 ";
                }
            }

            cout << endl;
        }
    }

    ~UpperTriangularMatrix() {
        delete []A;
    }
};


int main() {
    int n = 5;

    UpperTriangularMatrix L(5);

    L.columnModeSet(1,1, 1);
    L.columnModeSet(1,2, 1);
    L.columnModeSet(1,3, 1);
    L.columnModeSet(1,4, 1);
    L.columnModeSet(1,5, 1);
    L.columnModeSet(2,2, 1);
    L.columnModeSet(2,3, 1);
    L.columnModeSet(2,4, 1);
    L.columnModeSet(2,5, 1);
    L.columnModeSet(3,3, 1);
    L.columnModeSet(3,4, 1);
    L.columnModeSet(3,5, 1);
    L.columnModeSet(4,4, 1);
    L.columnModeSet(4,5, 1);
    L.columnModeSet(5,5, 1);

    L.display();

    return 0;
}
