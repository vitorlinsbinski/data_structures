#include <iostream>

using namespace std;

void countVowelsAndConsonants(char *c) {
    int i, vcount = 0, ccount = 0;

    for(i = 0; c[i] != '\0'; i++) {
        if(c[i] == 'a' || c[i] == 'e' ||  c[i] == 'i' || c[i] == 'o' || c[i] == 'u' || c[i] == 'A' || c[i] == 'E' || c[i] == 'I' || c[i] == 'O' || c[i] == 'U') {
            vcount++;
        } else if((c[i] >= 65 && c[i] <= 90) || (c[i] >= 97 && c[i] <= 122)){
            ccount++;
        }
    }

    cout << "There's " << vcount << " vowels in this String" << endl;
    cout << "There's " << ccount << " consonants in this String" << endl;
}

void countWords(char *c) {
    int i;
    int words = 1;

    for(i = 0; c[i] != '\0'; i++) {
        if(c[i] == ' ' && c[i + 1] != ' ') {
            words++;
        }
    }

    cout << "There's " << words << " words in this String" << endl;

}

int main() {
    char A[] = "How are   you";

    countVowelsAndConsonants(A);
    countWords(A);

    return 0;
}
