#include <iostream>

using namespace std;

struct Rectangle {
    int length;
    int breadth;
} r;

struct Complex {
    int real;
    int img;
};

struct Student {
    int roll;
    char name[25];
    char dept[10];
    char address[50];
};

struct Card {
    int face;
    int shape;
    int color;
};

int main() {
    r.breadth = 10;
    r.length = 5;

    cout << r.length << endl;
    cout << r.breadth << endl;

    struct Card deck[10] = {{1,0,0}, {2,1,0}, {1,1,1}, {3,0,1}};

    for(int i = 0; i < sizeof(deck)/sizeof(deck[0]); i++) {
        cout << deck[i].face << " " << deck[i].shape << " " << deck[i].color << endl;
    }

    return 0;
}
