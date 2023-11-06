#include <iostream>

using namespace std;

class SymmetricMatrix {
private:
    int *A;
    int n;

public:
    SymmetricMatrix(int s) {
        this -> n = s;
        A = new int[n * (n + 1) / 2];
    }

    void setElement(int i, int j, int x) {
        if(i >= j) {
            A[i*(i-1)/2 + j - 1] = x;
        }
    }

    int get(int i, int j) {

    }

    void d() {
        cout << "n:" << this -> n << endl;
        for(int i = 0; i < 15; i++) {
            cout << A[i] << " ";
        }

        cout << endl;
    }

    void Display() {
        int k = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i >= j) {
                    cout << A[k] << " ";
                    k++;
                } else {
                    cout << A[j * (j - 1) / 2 + i] << " ";
                }
            }
            cout << endl;
        }
    }



    ~SymmetricMatrix() {
        delete []A;
    }

};

int main() {
    int n = 5;

    SymmetricMatrix S(n);

    S.setElement(1,1, 2);
    S.setElement(2,1, 2);
    S.setElement(2,2, 3);
    S.setElement(3,1, 2);
    S.setElement(3,2, 3);
    S.setElement(3,3, 4);
    S.setElement(4,1, 2);
    S.setElement(4,2, 3);
    S.setElement(4,3, 4);
    S.setElement(4,4, 5);
    S.setElement(5,1, 2);
    S.setElement(5,2, 3);
    S.setElement(5,3, 4);
    S.setElement(5,4, 5);
    S.setElement(5,5, 6);


    S.d();

    S.Display();

    return 0;
}
