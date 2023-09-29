#include <iostream>

using namespace std;

//

int main() {
    int a = 10;

    // 'r' it's a reference to 'a'
    int &r = a;

    cout << "'a' value: " << a << endl;
    cout << "'r' value: " << r << endl;

    r++;

    cout << "'a' value: " << a << endl;
    cout << "'r' value: " << r << endl;

    int b = 5;
    int t = b;

    cout << "'b' value: " << b << endl;
    cout << "'t' value: " << t << endl;

    b++;

    cout << "'b' value: " << b << endl;
    cout << "'t' value: " << t << endl;

    // Why do this? It's useful in parameter passing
    // In other words, 'r' is an alias to 'a'

    return 0;
}
