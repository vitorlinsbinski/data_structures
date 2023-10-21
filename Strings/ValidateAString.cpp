#include <iostream>

using namespace std;

int valid(char *name) {
    int i;

    for(i = 0; name[i] != '\0'; i++) {
        if(!(name[i] >= 65 && name[i] <= 90) && !(name[i] >= 97 && name[i] <= 122) && !(name[i] >= 48 && name[i] <= 57)) {
            return false;
        }
    }

    return true;
}

int main() {
    char invalidName[] = "Ani?321";
    char validName[] = "Ani321";

    cout << invalidName << ": ";
    valid(invalidName) ? cout << "String is valid" : cout << "String is invalid";
    cout << endl;

    cout << validName << ": ";
    valid(validName) ? cout << "String is valid" : cout << "String is invalid";
    cout << endl;


    return 0;
}
