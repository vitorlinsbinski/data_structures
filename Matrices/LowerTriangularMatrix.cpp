#include <iostream>

using namespace std;

class LowerTriangularMatrix {
private:
    int *A;
    int n;

public:
    LowerTriangularMatrix(int n) {
        this -> n = n;
        A = new int[(n*(n + 1)) / 2];
    }

    void rowModeSet(int i, int j, int x) {
        if(i >= j) {
            A[i*(i-1)/2 + j - 1] = x;
        }
    }

    int rowModeGet(int i, int j) {
        if(i >= j) {
            return A[i*(i-1)/2 + j - 1];
        } else {
            return 0;
        }
    }

    void columnModeSet(int i, int j, int x) {
        if(i >= j) {
            A[(n*(j - 1) - ((j - 2)*(j - 1))/2) + i - j] = x;
        }
    }

    int columnModeGet(int i, int j) {
        if(i >= j) {
            return A[(n*(j - 1) - ((j - 2) - (j - 1))/2) + i - j];
        } else {
            return 0;
        }
    }


    void display() {
        int i, j;

        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                if(i >= j) {
                    cout << A[i] << " ";
                } else {
                    cout << "0 ";
                }
            }

            cout << endl;
        }
    }

    ~LowerTriangularMatrix() {
        delete []A;
    }
};


int main() {
    int n = 5;

    LowerTriangularMatrix L(5);

    L.columnModeSet(1,1, 1);
    L.columnModeSet(2,1, 1);
    L.columnModeSet(2,2, 1);
    L.columnModeSet(3,1, 1);
    L.columnModeSet(3,2, 1);
    L.columnModeSet(3,3, 1);
    L.columnModeSet(4,1, 1);
    L.columnModeSet(4,2, 1);
    L.columnModeSet(4,3, 1);
    L.columnModeSet(4,4, 1);
    L.columnModeSet(5,1, 1);
    L.columnModeSet(5,2, 1);
    L.columnModeSet(5,3, 1);
    L.columnModeSet(5,4, 1);
    L.columnModeSet(5,5, 1);

    L.display();

    return 0;
}
