#include <iostream>

using namespace std;

int main() {
    int A[3][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 4; j++) {
            cout << A[i][j] << " ";
        }
    }

    cout << endl;

    int *P[3];

    for(int k = 0; k < 3; k++) {
        P[k] = new int[4];
    }

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 4; j++) {
            P[i][j] = (i+1) * (j+1) + i;
        }
    }

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 4; j++) {
            cout << P[i][j] << " ";
        }
    }

    cout << endl;

    int **P1;

    P1 = new int*[3];

    for(int i  = 0; i < 3; i++) {
        P1[i] = new int[4];
    }

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 4; j++) {
            P1[i][j] = 25;
        }
    }

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 4; j++) {
            cout << P1[i][j] << " ";
        }
    }

    return 0;
}
