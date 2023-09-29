#include <iostream>

using namespace std;

int main() {
    int *p = new int[5];

    p[0] = 5;
    p[1] = 8;
    p[2] = 9;
    p[3] = 6;
    p[4] = 4;

    cout << "Array before to be increased: " << endl;
    for(int j = 0; j < 5; j++) {
        cout << p[j] << " ";
    }

    cout << endl;

    int *q = new int[10];

    for(int i = 0; i < 5; i++) {
        q[i] = p[i];
    }

    delete []p;

    p = q;

    q = nullptr;

    cout << "Array after to be increased: " << endl;
    for(int k = 0; k < 10; k++) {
        cout << p[k] << " ";
    }

    return 0;
}
