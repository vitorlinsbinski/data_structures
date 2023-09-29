#include <iostream>

using namespace std;

void tailRecursion(int n) {
    if(n > 0) {
        cout << n << " ";
        tailRecursion(n - 1);
    }
}

void headRecursion(int n) {
    if(n > 0) {
        headRecursion(n - 1);
        cout << n << " ";
    }
}


int main() {
    int x = 5;

    tailRecursion(x);
    cout << endl;
    headRecursion(x);
    return 0;
}
