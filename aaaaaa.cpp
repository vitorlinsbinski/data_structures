#include <iostream>

using namespace std;

int fatorial(int x) {
    if(x > 1) {
        return x * fatorial(x - 1);
    }
}

int main() {
    int n = 6;

    int f = fatorial(n);

    cout << f << endl;
    return 0;
}
