#include <iostream>

using namespace std;

int y = 0;

int GlobalVariable(int n) {
    if(n > 0) {
        y++;
        return GlobalVariable(n - 1) + y;
    }

    return 0;
}

int StaticVariable(int n) {
    static int x = 0;

    if(n > 0) {
        x++;
        return StaticVariable(n - 1) + x;
    }

    return 0;
}

int main() {
    int x = 5;

    cout << GlobalVariable(x);
    cout << endl;
    cout << StaticVariable(x);
    cout << endl;
    cout << StaticVariable(x);

    return 0;
}
