#include <iostream>

using namespace std;

class DiagonalMatrix {
private:
    int *A;
    int n;

public:
    DiagonalMatrix(int _n) {
        n = _n;
         A = new int[n];
    }

    void set(int i, int j, int x) {
        if(i == j) {
            A[i - 1] = x;
            cout << x << " was added succesfully!" << endl;
        } else {
            cout << "This element must be 0, because it's a Diagonal Matrice" << endl;
        }
    }

    int get(int i, int j) {
        if(i == j) {
            return  A[i - 1];
        } else {
            return 0;
        }
    }

    void display() {
        int i, j;

        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                if(i == j) {
                    cout << A[i] << " ";
                } else {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }

    ~DiagonalMatrix() {
        delete []A;
    }

};



int main() {
    int n = 4;

    DiagonalMatrix diagonal(n);

    diagonal.set(1, 1, 5);
    diagonal.set(2, 2, 8);
    diagonal.set(3, 3, 9);
    diagonal.set(4, 4, 12);

    diagonal.display();

    return 0;
}
