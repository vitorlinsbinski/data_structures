#include <iostream>

using namespace std;

template <class T>
class Arithametic {
private:
    T a;
    T b;

public:
    Arithametic(T a, T b);
    T add();
    T sub();
};

template <class T>
Arithametic<T>::Arithametic(T a, T b) {
    this -> a = a;
    this -> b = b;
}

template <class T>
T Arithametic<T>::add() {
    T c;
    c = a + b;
    return c;
}

template <class T>
T Arithametic<T>::sub() {
    T c;
    c = a - b;
    return c;
}

int main() {
    Arithametic<int> ar(10,5);

    cout << ar.add() << endl;
    cout << ar.sub() << endl;

    Arithametic<float> ar1(1.5, 1.2);

    cout << ar1.add() << endl;
    cout << ar1.sub() << endl;

    return 0;
}
