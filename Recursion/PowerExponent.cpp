#include <iostream>

using namespace std;

int power(int m, int n) {
    if(n == 0) {
        return 1;
    } else {
        return m * power(m, n - 1);
    }
}

// This version reduces the number of calls of the function by passing n as n / 2
int power2(int m, int n) {
    if(n == 0) {
        return 1;
    }

    if(n % 2 == 0) {
        return power2(m * m, n / 2);
    } else {
        return m * power2(m * m, n / 2);
    }
}

int main() {
    int result = power(2, 9);
    int result2 = power2(2, 9);

    cout << result;
    cout << endl;
    cout << result2;
    return 0;
}
