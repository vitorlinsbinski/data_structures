#include <iostream>

using namespace std;

void toUpperCase(char *c) {

    for(int i = 0; c[i] != '\0'; i++) {
        c[i] -= 32;
    }

}

void toLowerCase(char *c) {

    for(int i = 0; c[i] != '\0'; i++) {
        c[i] += 32;
    }

}

void toggleToLowercase(char *c) {
    for(int i = 0; c[i] != '\0'; i++) {
        if(c[i] >= 65 && c[i] <= 90) {
            c[i] += 32;
        }
    }
}

void toggleToUppercase(char *c) {
    for(int i = 0; c[i] != '\0'; i++) {
        if(c[i] >= 'a' && c[i] <= 122) {
            c[i] -= 32;
        }
    }
}

int main() {
    char s[]= "welcome";

    cout << s << endl;

    toUpperCase(s);

    cout << s << endl;

    toLowerCase(s);

    cout << s << endl;

    char s1[] = "StRUctUres";

    cout << s1 << endl;

    toggleToLowercase(s1);

    cout << s1 << endl;

    toggleToUppercase(s1);

    cout << s1 << endl;

    return 0;
}
