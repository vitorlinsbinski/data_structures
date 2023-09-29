#include <iostream>

using namespace std;

void fun(int x) {
    if(x > 0) {
        fun(x - 1);
        cout << x << endl;


    }
}

int fatorial(int x) {
    if(x > 0) {
        fatorial(x - 1);
        cout << x << endl;
    }

}

int main() {
    int n = 5;

    fatorial(n);
    return 0;
}
