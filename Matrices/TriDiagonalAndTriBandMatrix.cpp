#include <iostream>

using namespace std;

class TriDiagonalMatrix {
private:
    int *A;
    int n;
public:
    TriDiagonalMatrix(int s) {
        n = s;
        A = new int[3*n - 2];

        for (int i = 0; i < 3 * n - 2; i++) {
            A[i] = 0;
        }
    }

    setElement(int i, int j, int x) {
        if(i - j == 1) {
            A[i - 2] = x;
        } else if(i - j == 0) {
            A[(n - 1) + (i - 1)] = x;
        } else if(i - j == -1) {
            A[(2 * n - 1) + (i - 1)] = x;
        }
    }

    void d() {
        for(int i = 0; i < 13; i++) {
            cout << A[i] << " ";
        }

        cout << endl;
    }

    void Display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i - j == 1) {
                    cout << A[i - 2] << " ";
                } else if (i - j == 0) {
                    cout << A[3 + i] << " ";
                } else if (i - j == -1) {
                    cout << A[i + 8] << " ";
                } else {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }



    ~TriDiagonalMatrix() {
        delete []A;
    }
};

int main() {
    TriDiagonalMatrix T(5);

    T.setElement(1, 1, 2);
    T.setElement(1, 2, 3);
    T.setElement(2, 1, 1);
    T.setElement(2, 2, 2);
    T.setElement(2, 3, 3);
    T.setElement(3, 2, 1);
    T.setElement(3, 3, 2);
    T.setElement(3, 4, 3);
    T.setElement(4, 3, 1);
    T.setElement(4, 4, 2);
    T.setElement(4, 5, 3);
    T.setElement(5, 4, 1);
    T.setElement(5, 5, 2);

    T.d();

    T.Display();

    return 0;
}
