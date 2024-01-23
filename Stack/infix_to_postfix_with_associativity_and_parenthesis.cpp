#include <iostream>
#include <stack>
#include <cstring>
#include <map>

using namespace std;

string convertInfixToPostfix(string &exp) {
        string newExp = "";

    map<char, int> outStackPriority = {
        {'+', 1}, {'-', 1},
        {'*', 3}, {'/', 3},
        {'^', 6}, {'(', 7},
        {')', 0},
    };

    map<char, int> inStackPriority = {
        {'+', 2}, {'-', 2},
        {'*', 4}, {'/', 4},
        {'^', 5}, {'(', 0},
    };

    stack<char> chStack;

    for(char ch : exp) {
        if(ch != ' ') {
            if(isalpha(ch)) {
                newExp += ch;
            } else {
                while(!chStack.empty() && inStackPriority[chStack.top()] > outStackPriority[ch]) {
                    newExp += chStack.top();
                    chStack.pop();
                }

                if(ch != ')') {
                    chStack.push(ch);
                } else {
                    chStack.pop();
                }

            }

        }
    }

    while(!chStack.empty()) {
        newExp += chStack.top();
        chStack.pop();
    }

    return newExp;
}

int main() {
    string expression = "(a+b)/(c^d)^e";

    cout << convertInfixToPostfix(expression) << endl;
    return 0;
}
