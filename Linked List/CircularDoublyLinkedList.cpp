#include <iostream>
#include <limits.h>

using namespace std;

class Node {
private:
    int data;
    Node *prev;
    Node *next;

public:
    Node(int data) {
        this->data = data;
        prev = nullptr;
        next = nullptr;
    }

    ~Node() {}

    friend class CircularDoublyLinkedList;
};

class CircularDoublyLinkedList {
private:
    Node *head;
    int length;

public:
    CircularDoublyLinkedList() {
        head = nullptr;
        length = 0;
    }

    void push(int data) {
        Node *node = new Node(data);

        if(head == nullptr) {
            head = node;
            node -> next = head;
            node -> prev = head;

            length++;

            return;
        }


        Node *aux = head;

        while(aux -> next != head) {
            aux = aux -> next;
        }

        aux -> next = node;
        node -> prev = aux;
        node -> next = head;
        head -> prev = node;


        length++;
    }

    void insert(int data, int index) {
        Node *node = new Node(data);

        Node *aux;

        if(index == 0) {
            if(head == nullptr) {
                head = node;
                node -> next = head;
                node -> prev = head;
            } else {
                node -> next = head;
                node -> prev = head -> prev;
                head -> prev -> next = node;
                head -> prev = node;
                head = node;
            }


            length++;

            return;
        }

        aux = head;

        for(int i = 0; i < index - 1; i++) {
            aux = aux -> next;
        }

        node -> next = aux -> next;
        node -> prev = aux;
        aux -> next -> prev = node;
        aux -> next = node;

        length++;
    }

    void display() {
        if(head == nullptr) {
            cout << "List is empty..." << endl;
            return;
        }

        Node *aux = head;

        do {
            cout << " <- " << aux->data << " -> ";
            aux = aux -> next;

            if(aux == head) {
                cout << "( " << aux -> data << " )";
            }

        } while(aux != head);

        cout << endl;
    }

    void getNeighbors(int index) {
        cout << "length: " << length << endl;

        if(head == nullptr) {
            cout << "List is empty..." << endl;
            return;
        }

        if(index < 0 || index >= length) {
            cout << "Index is invalid..." << endl;
            return;
        }

        Node *aux = head;

        for(int i = 0; i < index; i++) {
            aux = aux -> next;
        }

        cout << "previous: ";
        cout << aux -> prev -> data << endl;

        cout << "target: ";
        cout << aux -> data << endl;

        cout << "next: ";
        cout << aux -> next -> data << endl;
    }

    int getMiddleTermByLength() {
        if(head == nullptr) {
            cout << "List is empty..." << endl;
            return 0;
        } else {
            Node *p = head;
            int lengthList = 0;

            do {
                p = p -> next;
                lengthList++;
            } while(p != head);

            p = head;

            for(int i = 0; i < lengthList/2; i++) {
                p = p -> next;
            }

            return p -> data;

        }
    }

    int getMiddleTerm() {
        if(head == nullptr) {
            cout << "List is empty..." << endl;
            return 0;
        } else {
            Node *p = head;
            Node *q = p;

            do {
                p = p -> next -> next;
                q = q -> next;
            } while(p != head && p -> next != head);

            return q -> data;

        }

    }

    ~CircularDoublyLinkedList(){}
};

int main() {
    CircularDoublyLinkedList L;

    L.insert(1,0);
    L.insert(2,1);
    L.insert(3,2);
    L.insert(4,3);
    L.insert(5,4);

    L.insert(99,2);

    L.insert(159,4);
    L.insert(987,4);
    L.insert(1258,4);
    L.insert(66,4);

    L.display();
    L.getNeighbors(6);

    cout << "Middle: " << L.getMiddleTerm() << endl;
    cout << "Middle: " << L.getMiddleTermByLength() << endl;

    return 0;
}
