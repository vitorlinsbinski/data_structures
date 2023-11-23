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

    friend class DoublyLinkedList;
};

class DoublyLinkedList {
private:
    Node *head;
    int length;

public:
    DoublyLinkedList() {
        head = nullptr;
        length = 0;
    }

    void push(int data) {
        Node *node = new Node(data);

        if(head == nullptr) {
            head = node;
        } else {
            Node *aux = head;

            while(aux -> next != nullptr) {
                aux = aux -> next;
            }

            aux -> next = node;
            node -> prev = aux;

        }

        length++;
    }

    void insert(int data, int index) {
        Node *node = new Node(data);

        if(index < 0 || index > length) {
            cout << "It's not possible to insert an element at this index" << endl;
        } else {
            if(head == nullptr) {
                head = node;
            } else {
                if(index == 0) {
                    head -> prev = node;
                    node -> next = head;
                    head = node;
                } else {
                    Node *aux = head;

                    for(int i = 0; i < index - 1; i++) {
                        aux = aux -> next;
                    }

                    node -> next = aux -> next;
                    node -> prev = aux;
                    if(aux -> next != nullptr) {
                        aux -> next -> prev = node;
                    }
                    aux -> next = node;

                }


            }
        }

        length++;
    }

    void deleteElement(int index) {
        if(head == nullptr) {
            cout << "List is empty..." << endl;
            return;
        }

        if(index < 0 || index >= length) {
            cout << "This index is invalid" << endl;
            return;
        }


        Node *aux = head;

        if(index == 0) {
            if(aux -> next) {
                aux -> next -> prev = nullptr;
            }

            head = aux -> next;
            delete aux;
        } else {
            for(int i = 0; i < index; i++) {
                aux = aux -> next;
            }

            aux -> prev -> next = aux -> next;

            if(aux -> next) {
                aux -> next -> prev = aux -> prev;
            }

            delete aux;
        }

        length--;
    }

    void display() {
        if(head == nullptr) {
            cout << "List is empty" << endl;
        } else {
            Node *aux = head;

            while(aux) {
                cout << " <- " << aux -> data << " -> ";
                aux = aux -> next;
            }

        }

        cout << endl;
    }

    void getNeightbors(int index) {
        if(head == nullptr) {
            cout << "List is empty" << endl;
        } else {
            if(index < 0 || index > length - 1) {
                cout << "This index is invalid!" << endl;
            } else {
                Node *aux = head;

                for(int i = 0; i < index; i++) {
                    aux = aux -> next;
                }

                cout << "previous: ";
                aux -> prev == nullptr ? cout << "null" << endl : cout << aux -> prev -> data << endl;
                cout << "target: " << aux -> data << endl;
                cout << "next: ";
                aux -> next == nullptr ? cout << "null" << endl : cout << aux -> next -> data << endl;
            }

        }
    }

    void reverse() {
        if (head == nullptr || head->next == nullptr) {
            cout << "List has 0 or 1 element, no need to reverse" << endl;
            return;
        }

        Node *aux = head;
        Node *temp;

        while(aux) {
            temp = aux->next;
            aux->next = aux->prev;
            aux->prev = temp;

            if (temp == nullptr) {
                head = aux;
                break;
            }

            aux = temp;
        }
    }


    ~DoublyLinkedList() {}
};

int main() {
    DoublyLinkedList L;

    L.insert(1,0);
    L.insert(2,1);
    L.insert(3,2);
    L.insert(4,3);
    L.insert(5,4);
    L.insert(99,0);

    L.display();

    L.getNeightbors(2);

    cout << "Deleting..." << endl;
    L.deleteElement(0);
    L.display();

    cout << "Reversing..." << endl;
    L.reverse();
    L.display();

    return 0;
}
