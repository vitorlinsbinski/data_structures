#include <iostream>

using namespace std;

int factorial(int n) {
    if(n == 0) {
        return 1;
    }

    if(n > 0) {
        return factorial(n - 1) * n;
    }
}

int nCr2(int n, int r) {
    int num, den;

    num = factorial(n);
    den = factorial(r) * factorial(n - r);

    return num / den;
}

int nCr(int n, int r) {
    if(r == 0 || n == r) {
        return 1;
    } else {
        return nCr(n - 1, r - 1) + nCr(n - 1, r);
    }
}

int main() {
    int result = nCr(4, 2);
    int result2 = nCr2(4, 2);

    cout << result << endl;
    cout << result2 << endl;

    return 0;
}
