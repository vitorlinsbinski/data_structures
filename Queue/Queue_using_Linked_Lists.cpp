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

    void insert(int data) {
        Node *node = new Node(data);

        if(isEmpty()) {
            f = node;
            r = f;
        } else {
            r -> next = node;
            r = node;
        }
    }

    void remove() {
        if(!isEmpty()) {
            Node *temp = f;

            f = f -> next;

            delete temp;
        } else {
            cout << "Queue is empty, it's not possible to delete an element." << end;;
        }
    }

    void display() {
        if(!isEmpty()) {
            Node *aux = f;

            do {
                cout << aux -> data << " | ";
                aux = aux -> next;
            } while(aux != nullptr);

            cout << endl;
        } else {
            cout << "Queue is empty, there's anything to show." << endl;
        }
    }

    ~LinkedList() {}
};

class Queue {
private:
    LinkedList *q;

public:
    Queue() {
        q = new LinkedList;
    }


    void enqueue(int data) {
        q -> insert(data);
    }

    void dequeue() {
        q -> remove();
    }

    void display() {
        q -> display();
    }

    ~Queue() {}
};

int main() {
    Queue myQueue;
    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);
    myQueue.enqueue(4);
    myQueue.enqueue(5);

    myQueue.display();

    myQueue.dequeue();
    myQueue.dequeue();

    myQueue.display();
    return 0;
}
