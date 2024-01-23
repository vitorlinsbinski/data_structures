#include <iostream>

using namespace std;

class Node {
private:
    int data;
    Node *next;
public:
    Node(int data) {
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

    void push(int data) {
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

int main() {
    Stack myStack;

    cout << "Adding five elements: " << endl;

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.push(5);

    myStack.print();

    cout << "The top element is: " << myStack.peek() << endl;

    cout << "Element in position 2 is: " << myStack.get(2) << endl;

    cout << "Deleting two elements: " << endl;

    myStack.pop();
    myStack.pop();

    myStack.print();

    cout << "The top element is: " << myStack.peek() << endl;


    return 0;
}
