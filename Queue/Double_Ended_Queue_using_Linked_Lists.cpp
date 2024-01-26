#include <iostream>

using namespace std;

class Node {
private:
    int data;
    Node *next;

public:
    Node(int data) {
        this -> data = data;
        next = nullptr;
    }

    ~Node() {}

    friend class LinkedList;
};

class LinkedList {
private:
    Node *f;
    Node *r;

public:
    LinkedList() {
        f = nullptr;
        r = nullptr;
    }

    bool isEmpty() {
        return f == nullptr;
    }

    void pushBack(int data) {
        Node *node = new Node(data);

        if(isEmpty()) {
            f = r = node;
        } else {
            r -> next = node;
            r = node;
        }
    }

    void pushFront(int data) {
        Node *node = new Node(data);

        if(isEmpty()) {
            f = r = node;
        } else {
            node -> next = f;

            f = node;
        }

    }

    void popBack() {
        if(!isEmpty()) {
            if(f == r) {
                delete r;
                f = r = nullptr;
            } else {
                Node *aux = f;

                while(aux -> next != r) {
                    aux = aux -> next;
                }

                delete r;
                r = aux;
                r -> next = nullptr;
            }
        }
    }

    void popFront() {
        if(!isEmpty()) {
            Node *temp = f;

            if(f == r) {
                delete f;
                f = r = nullptr;
            } else {
                f = f -> next;
            }


            delete temp;
        }
    }



    void display() {
        if(!isEmpty()) {
            Node *aux = f;

            while (aux != nullptr) {
                cout << aux->data << " | ";
                aux = aux->next;
            }

            cout << endl;
        } else {
            cout << "Queue is empty, there's anything to show." << endl;
        }
    }

    ~LinkedList() {}
};

class DoubleEndedQueue {
private:
    LinkedList *q;

public:
    DoubleEndedQueue() {
        q = new LinkedList;
    }


    void pushBack(int data) {
        q -> pushBack(data);
    }

    void pushFront(int data) {
        q -> pushFront(data);
    }

    void popBack() {
        q -> popBack();
    }

    void popFront() {
        q -> popFront();
    }


    void display() {
        q -> display();
    }

    ~DoubleEndedQueue() {}
};

int main() {
    DoubleEndedQueue myQueue;

    myQueue.pushBack(1);
    myQueue.pushBack(2);
    myQueue.pushBack(3);


    myQueue.display();

    myQueue.pushFront(4);
    myQueue.pushFront(5);
    myQueue.pushFront(6);

    myQueue.display();

    myQueue.popBack();
    myQueue.popBack();
    myQueue.popBack();

    myQueue.display();

    myQueue.popFront();
    myQueue.popFront();
    myQueue.popFront();

    myQueue.display();

    return 0;
}
