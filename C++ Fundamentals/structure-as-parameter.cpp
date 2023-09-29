#include <iostream>

using namespace std;

struct Rectangle {
    int length;
    int breadth;
};

struct Test {
    int A[5];
    int n;
};

int area(struct Rectangle x) {
    return (x.length) * (x.breadth);
}

void changeStructValues(struct Rectangle* x) {
    x -> length = 100;
    x -> breadth = 50;
}

void fun(struct Test t1) {

}

struct Rectangle* newRectangle() {
    struct Rectangle *p;

    p = new Rectangle;

    return p;
};

int main() {
    struct Rectangle r = {10,5};
    struct Test t = {{10,20,30,40,50}, 5};

    cout << r.length << " " << r.breadth << endl;

    struct Rectangle *p;

    p = &r;

    int a = area(r);

    cout << a << endl;

    changeStructValues(p);

    cout << r.length << " " << r.breadth << endl;

    int a1 = area(r);

    cout << a1 << endl;

    struct Rectangle* myNewRectangle = newRectangle();


    myNewRectangle -> length = 2;
    myNewRectangle -> breadth = 1;

    cout << myNewRectangle -> length << endl;
    cout << myNewRectangle -> breadth << endl;


    return 0;
}
