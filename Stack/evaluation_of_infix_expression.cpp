#include <iostream>
#include <stack>
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
            if(isdigit(ch)) {
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

using OperationFunction = int (*)(int, int);

int evaluateInfixExpression(string &exp) {
    string postFixForm = convertInfixToPostfix(exp);

    map<char, OperationFunction> makeOperation = {
        {
            '+',
            [](int a, int b) { return a + b; }
        },
        {
            '-',
            [](int a, int b) { return a - b; }
        },
        {
            '*',
            [](int a, int b) { return a * b; }
        },
        {
            '/',
            [](int a, int b) { return a / b; }
        },
        {
            '^',
            [](int a, int b) {
                int result = 1;

                for(int i = 0; i < b; i++) {
                    result *= a;
                }

                return result;
            }
        }
    };

    stack<int> operandsStack;

    for(char ch : postFixForm) {
        if(!isdigit(ch)) {
            int secondOperand = operandsStack.top();
            operandsStack.pop();

            int firstOperand = operandsStack.top();
            operandsStack.pop();

            int result = makeOperation[ch](firstOperand, secondOperand);
            operandsStack.push(result);
        } else {
            operandsStack.push(ch - '0');
        }
    }

    return operandsStack.top();
}

int main() {
    string infixExpression = "6 + 5 + 3 * 4";
    int result = evaluateInfixExpression(infixExpression);
    cout << "Result: " << result << endl;

    return 0;
}
