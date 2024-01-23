#include <iostream>
#include <stack>
#include <cstring>
#include <map>

using namespace std;

string convertInfixToPostfix(string &exp) {
    string newExp = "";

    map<char, int> opPriority = {
        {'+', 1}, {'-', 1},
        {'*', 2}, {'/', 2},
        {'a', 3}, {'b', 3},
        {'c', 3}, {'d', 3},
        {'e', 3}, {'f', 3}
    };

    stack<char> opStack;

    for(char ch : exp) {
        if(ch != ' ') {
            while(!opStack.empty() && opPriority[opStack.top()] >= opPriority[ch]) {
                newExp += opStack.top();
                opStack.pop();
            }

            opStack.push(ch);
        }
    }

    while(!opStack.empty()) {
        newExp += opStack.top();
        opStack.pop();
    }

    return newExp;
}

int main() {
    string expression = "a+b*c-d/e";

    cout << convertInfixToPostfix(expression) << endl;

    return 0;
}
