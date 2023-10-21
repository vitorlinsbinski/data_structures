#include <iostream>

using namespace std;

int main() {
    char temp = 'A';

    printf("Value of 'A' in ASCII code: %d\n", temp);
    printf("Value of '65' in ASCII decoded: %c\n", temp);
    cout << temp << endl;

    char alphabet[5] = {'A', 'B', 'C', 'D', 'E'};

    char x[5] = {65, 66, 67, 68, 69};

    char name[] = {'J', 'o', 'h', 'n', '\0'};

    for(int i = 0; i < 5; i++) {
        cout << name[i] << endl;
    }

    char myName[] = "Vitor";

    cout << myName << endl;


    char yourName[10];
    cout << "Tell me your last name: ";
    scanf("%s", &yourName);
    gets(yourName);
    cout << "Your last name is " << yourName << endl;

    return 0;
}
