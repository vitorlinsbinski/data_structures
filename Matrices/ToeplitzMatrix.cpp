#include <iostream>

using namespace std;

class ToeplitzMatrix{
private:
    int *A;
    int n;
public:
    ToeplitzMatrix(int s) {
        n = s;
        A = new int[2*n - 1];
    }

    void setElement(int i, int j, int x) {
        if(i <= j) {
            A[j - 1] = x;
        } else if(i > j) {
            A[n + (i - j - 1)] = x;
        }
    }

    void d() {
        cout << "n: " << n << endl;
        cout << "size: " << 2*n - 1 << endl;

        for(int i = 0; i < 2*n - 1; i++) {
            cout << A[i] << " ";
        }

        cout << endl;
    }

    void Display() {
        int i, j;

        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                if(i <= j) {
                    cout << A[j - i] << " ";
                } else if(i > j) {
                    cout << A[4 + (i - j)] << " ";
                }
            }

            cout << endl;
        }
    }

    ~ToeplitzMatrix() {
        delete []A;
    }
};

int main() {
    ToeplitzMatrix M(5);

    M.setElement(1, 1, 2);
    M.setElement(1, 2, 3);
    M.setElement(1, 3, 4);
    M.setElement(1, 4, 5);
    M.setElement(1, 5, 6);

    M.setElement(2, 1, 7);
    M.setElement(3, 1, 8);
    M.setElement(4, 1, 9);
    M.setElement(5, 1, 10);

    //M.d();

    M.Display();

    return 0;
}
