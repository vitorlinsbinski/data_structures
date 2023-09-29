#include <iostream>

using namespace std;

int factorial(int n) {
    if(n == 0) {
        return 1;
    } else if(n > 0) {
        return factorial(n - 1) * n;
    }
    return -1;
}

int main() {
    int result = factorial(5);

    cout << result;
}
