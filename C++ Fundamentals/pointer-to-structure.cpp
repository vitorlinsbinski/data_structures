#include <iostream>

using namespace std;

struct Rectangle {
    int length;
    int breadth;
} r, *p, *p1;

int main() {
    r.length = 10;
    r.breadth = 5;

    p = &r;

    cout << r.length << endl;
    cout << r.breadth << endl;

    p ->length = 20;
    p ->breadth = 10;

    cout << r.length << endl;
    cout << r.breadth << endl;

    cout << p << endl;

    // p1 = (struct Rectangle*)malloc(sizeof(struct Rectangle)); [In C]
    p1 = new Rectangle; // In C++

    p1 ->length = 25;
    p1->breadth = 15;


    cout << p1 -> length << endl;
    cout << p1 -> breadth << endl;

    // p1 � o endere�o da estrutura Rectangle, &p1 � o endere�o onde essa vari�vel est�
    cout << p1 << " " << &p1 << endl;

    return 0;
}
