#include <iostream>

using namespace std;


void foo(int n, int sum) {

    int k = 0, j = 0;

    if (n == 0) return;

    k = n % 10;

    j = n/10;

    sum = sum + k;

    foo(j, sum);

    cout << k << endl;

}

int f(int &x, int c) {

    c = c - 1;

    if (c == 0) return 1;

    x = x + 1;

    return f(x,c) * x;

}

void teste(int &y) {
    cout << y << endl;

    y = y - 1;

    cout << y << endl;
}

int fun(int n){

    int x=1, k;

    if (n==1) return x;

    for (k=1; k<n; ++k)

    x=x + fun (k) * fun (n - k);

    return x;

}

void count(int n) {

    static int d = 1;

    printf("%d", n);

    printf("%d", d);

    d++;

    if (n > 1) count (n-1);

    printf("%d", d);

}


int main () {

    int a = 2048, sum = 0;

    foo(a, sum);

    int x = 5;

    int result = f(x, 5);
    cout << result << endl;

    int y = 7;

    teste(y);

    int result2 = fun(5);

    cout << result2 << endl;

    int result3 = count(3);

    cout << result3 << endl;
}
