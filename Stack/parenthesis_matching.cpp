#include <iostream>

using namespace std;

class Node {
private:
    char data;
    Node *next;
public:
    Node(char data) {
        this -> data = data;
        this -> next = nullptr;
    }

    ~Node() {}

    friend class Stack;
};

class Stack {
private:
    Node *top;

public:
    Stack() {
        top = nullptr;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(char data) {
        Node *node = new Node(data);

        if(node == nullptr) {
            cout << "Stack overflow..." << endl;
            return;
        }

        node -> next = top;
        top = node;
        return;
    }

    void pop() {
        if(isEmpty()) {
            cout << "The stack is empty, so it's impossible to delete any element" << endl;
            return;
        }

        Node *target = top;

        top = top -> next;

        delete target;
    }

    int peek() {
        if(isEmpty()) {
            cout << "The stack is empty, so there's no element to peek." << endl;
            return -1;
        }

        return top -> data;
    }

    int get(int pos) {
        if(isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }

        Node *aux = top;

        for(int i = 0; aux && i < pos - 1; i++) {
            aux = aux -> next;
        }

        if(aux) {
            return aux -> data;
        } else {
            return -1;
        }
    }

    void print() {
        if(isEmpty()) {
            cout << "The stack is empty, so it's not possible to print any element." << endl;
            return;
        }

        Node *aux = top;

        while(aux != nullptr) {
            cout << aux -> data << endl;
            aux = aux -> next;
        }
    }
};

bool checkParenthesisMatching(char str[]) {
    Stack S;

    int stringSize = sizeof(str) - 1;

    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] == '(') {
            S.push(str[i]);
        } else if(str[i] == ')') {
            if(!S.isEmpty()) {
                S.pop();
            } else {
                return false;
            }
        }
    }

    return S.isEmpty();
}


int main() {
    char str[] = "((((a+b)*(c-d))))";

    if(checkParenthesisMatching(str)) {
        cout << "The parenthesis are matching!" << endl;
    } else {
        cout << "The parenthesis are NOT matching!" << endl;
    }

    return 0;
}
