#include <iostream>

using namespace std;

int nOfCallsMemo = 0;
int nOfCallsNormalRecursive = 0;

int fib(int n) {
    nOfCallsNormalRecursive++;


    if(n == 0) {
        return 0;
    }

    if(n == 1) {
        return 1;
    }

    if(n > 1) {
        return fib(n - 2) + fib(n - 1);
    }
}

int fibIterativeVersion(int n) {
    int t0 = 0, t1 = 1;
    int s = 0, i;

    for(i = 2; i <= n; i++) {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }

    return s;
}

int fibTimesComplexityReduced(int n) {
    static int f[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    nOfCallsMemo++;

    if(n <= 1) {
        f[n] = n;
        return n;
    } else {
        if(f[n - 2] == -1) {
            f[n - 2] = fibTimesComplexityReduced(n - 2);
        }
        if(f[n - 1] == -1) {
            f[n - 1] = fibTimesComplexityReduced(n - 1);
        }
    }

    f[n] = f[n - 2] + f[n - 1];
    return f[n];
}

int main() {
    int result = fib(5);
    int resultIterative = fibIterativeVersion(5);
    int resultTimesComplexityReduced = fibTimesComplexityReduced(5);

    cout << result  << endl;
    cout << resultIterative  << endl;
    cout << resultTimesComplexityReduced  << endl;

    cout << "Number of calls of Fibonacci Normal Recursive Function: " << nOfCallsNormalRecursive << endl;
    cout << "Number of calls of Fibonacci Memorization Function: " << nOfCallsMemo << endl;


}
