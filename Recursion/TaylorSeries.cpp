#include <iostream>

using namespace std;

int sum(int n) {
    if(n == 0) {
        return 0;
    } else {
        return sum(n - 1) + n;
    }
}

int factorial(int n) {
    if(n == 0) {
        return 1;
    } else {
        return factorial(n - 1) * n;
    }
}

int power(int m, int n) {
    if(n == 0) {
        return 1;
    }

    if(n % 2 == 0) {
        return power(m * m, n / 2);
    } else {
        return m * power(m * m, n / 2);
    }
}

double TaylorSeries(int x, int n) {

    if(n > 0) {
        return (static_cast<double>(power(x, n)) / static_cast<double>(factorial(n))) + TaylorSeries(x, n - 1);
    } else {
        return 1;
    }

}

double TaylorSeries2(int x, int n) {
    static double p = 1, f = 1;

    double r;

    if(n == 0) {
        return 1;
    } else {
        r = TaylorSeries2(x, n - 1);
        p = p * x;
        f = f * n;

        return r + p/f;
    }
}

int main() {
    float result = TaylorSeries(1, 15);

    float result2 = TaylorSeries2(1, 15);

    cout << result << endl;
    cout << result2 << endl;
    return 0;
}
