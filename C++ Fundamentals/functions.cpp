#include <iostream>

using namespace std;

// Function is a grouping instructions
// Functions are also called as modules or procedures
// Monolithic Programming is a program that has all in one place
// Modular Programming or Procedural Programming is a program that separates functions and methods in pieces of code

// In pass by value, any changes made in the function will not reflect in actual parameters
// In pass by address, formal parameters must be pointers (*)
// In pass by reference, formal parameters must be references (&)

// DISCLAIMER: It's not appropriate to use parameters by passing reference in functions that have a lot of loops and logic involved

// Pass by value (wrong way to swap elements)
void swap(int x, int y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
}

// Pass by address
void swapByAddress(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

// Pass by reference
void swapByReference(int &x, int &y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
}

int main() {
    int a,b;
    a = 10;
    b = 20;
    swap(a, b);

    cout << a << " " << b << endl;

    int c,d;
    c = 10;
    d = 20;
    swapByAddress(&c, &d);

    cout << c << " " << d << endl;

    int e,f;
    e = 10;
    f = 20;
    swapByReference(e, f);

    cout << e << " " << f << endl;


    return 0;
}


