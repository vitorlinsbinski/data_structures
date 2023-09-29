#include <iostream>

using namespace std;

int main() {
    int A[10] = {2,4,6,8,10};

    int *p;

    p = new int[5];

    p[0] = 1;
    p[1] = 2;
    p[2] = 3;
    p[3] = 4;
    p[4] = 5;

    for(int i = 0; i < 5; i++) {
        cout << A[i] << " ";
    }

    cout << endl;

    for(int i = 0; i < 5; i++) {
        cout << p[i] << " ";
    }

    cout << endl;

    cout << "Address of pointer p: " << p << " | That is equal to the address of the first element of the Array that is pointed by p:" << &p[0] << endl;

    cout << endl;

    cout << "The first element of the Array that is pointed by p can be accessed in this way: *p: " << *p << endl;

    delete []p;

    return 0;
}
