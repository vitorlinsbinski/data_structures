#include <iostream>

using namespace std;

int fun(int n) {
    if(n > 100) {
        return n - 10;
    } else {
        fun(fun(n + 11));
    }
}

int main() {
    int result = fun(30);

    cout << result;

    return 0;
}
