#include <iostream>
#include <limits.h>

using namespace std;

class Node {
private:
    int data;
    Node *next;

public:
    Node(int data, Node *head) {
        this->data = data;
        next = head;
    }

    ~Node() {}

    friend class CircularLinkedList;
};

class CircularLinkedList {
private:
    Node *head;
    int length;

public:
    CircularLinkedList() {
        head = nullptr;
        this->length = 0;
    }

    void push(int data) {
        Node *node = new Node(data, head);

        if (head == nullptr) {
            head = node;
            head->next = head;
        } else {
            Node *aux = head;

            while (aux->next != head) {
                aux = aux->next;
            }

            aux->next = node;
        }

        length++;
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
        } else {
            Node *aux = head;

            do {
                cout << aux->data << " -> ";
                aux = aux->next;

                if(aux == head) {
                    cout << "( " << aux -> data << " )";
                }

            } while (aux != head);

            cout << endl;
        }
    }

    void _displayRecursively(Node *node) {
        static int flag = 0;

        if(node != head || flag == 0) {
            flag = 1;
            cout << node -> data << " -> ";
            _displayRecursively(node -> next);
        }

        flag = 0;
    }

    void displayRecursively() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
        } else {
            _displayRecursively(head);
            cout << endl;
        }
    }

    void insert(int data, int index) {
        Node *node = new Node(data, head);

        if (head == nullptr) {
            head = node;
            head->next = head;
        } else {
            if (index < 0 || index > length) {
                cout << "It's not possible to insert at this index" << endl;
            } else {
                Node *aux = head;

                if (index == 0) {
                    node->next = head;

                    while (aux->next != head) {
                        aux = aux->next;
                    }

                    aux->next = node;
                    head = node;
                } else {
                    for (int i = 0; i < index - 1; i++) {
                        aux = aux->next;
                    }

                    node->next = aux->next;
                    aux->next = node;
                }


            }
        }

        length++;
    }

    void deleteAtIndex(int index) {
        cout << "length: " << length << endl;
        if(head == nullptr){
            cout << "List is empty";
        } else {
            if(index < 0 || index > length - 1) {
                cout << "It's not possible to insert at this index" << endl;
            } else {
                Node *p = nullptr;
                Node *aux = head;

                if(index == 0) {
                    p = head;

                    while (aux->next != head) {
                        aux = aux->next;
                    }

                    if(head -> next == head) {
                        delete head;
                        head = nullptr;
                    } else {
                        aux -> next = head -> next;
                        head = head -> next;
                        delete p;
                    }


                } else {
                    for (int i = 0; i < index; i++) {
                        p = aux;
                        aux = aux->next;
                    }

                    p -> next = aux -> next;
                    delete aux;
                }
            }
        }

        length--;

        cout << "length: " << length << endl;
    }


    ~CircularLinkedList() {}
};

int main() {
    CircularLinkedList L;

    L.insert(1,0);
    L.display();

    cout << "Deleting..." << endl;
    L.deleteAtIndex(0);
    L.display();

    L.insert(2,0);
    L.insert(3,0);
    L.insert(4,0);
    L.insert(5,0);
    L.display();



    return 0;
}
