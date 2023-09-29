#include <iostream>

using namespace std;

class Rectangle {
private:
    int length;
    int breadth;

public:
    Rectangle(int l, int b) {
        length = l;
        breadth = b;
    }

    int area() {
        return length * breadth;
    }

    int changeLength(int l) {
        length = l;
    }
};

int main() {
    Rectangle r(10, 5);

    int a = r.area();
    r.changeLength(20);

    return 0;
}
