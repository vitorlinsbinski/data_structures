#include <iostream>
#include <limits.h>

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

    ~Node() {

    }

    friend class LinkedList;
};

class LinkedList {
private:
    Node *head;
    int length;
public:
    LinkedList() {
        head = nullptr;
        length = 0;
    }

    int getLength() {
        return length;
    }

    int getSum() {
        int sum = 0;

        if(head == nullptr) {
            return 0;
        } else {
            Node *aux = head;

            while(aux) {
                sum += aux -> data;
                aux = aux -> next;
            }
        }

        return sum;
    }

    int getMax() {
        int max = INT_MIN;

        if(head == nullptr) {
            return 0;
        } else {
            Node *aux = head;

            while(aux) {
                if(aux -> data > max) {
                    max = aux -> data;
                }

                aux = aux -> next;
            }
        }

        return max;
    }

    int getMin() {
        int min = INT_MAX;

        if(head == nullptr) {
            return 0;
        } else {
            Node *aux = head;

            while(aux) {
                if(aux -> data < min) {
                    min = aux -> data;
                }

                aux = aux -> next;
            }
        }

        return min;
    }

    Node *search(int key) {
        if(head == nullptr) {
            return nullptr;
        } else {
            Node *aux = head;

            while(aux && aux -> data != key) {
                aux = aux -> next;
            }

            return aux != nullptr ? aux : nullptr;
        }

    }

    Node *searchByMovingToHead(int key) {
        if(head == nullptr) {
            return nullptr;
        } else {
            Node *prev = nullptr;
            Node *aux = head;

            while(aux && aux -> data != key) {
                prev = aux;
                aux = aux -> next;
            }

            if(aux) {
                prev -> next = aux -> next;
                aux -> next = head;
                head = aux;

                return aux;
            } else {
                return nullptr;
            }
        }
    }

    void push(int data) {
        if(head == nullptr) {
            head = new Node(data);
        } else {
            Node *aux;
            aux = head;

            Node *node = new Node(data);

            while(aux -> next != nullptr) {
                aux = aux -> next;
            }

            aux -> next = node;

        }

        length++;
    }

    void insert(int data, int index) {
        if(index < 0 || index > length) {
            cout << "It's not possible to insert this element at this index because it's invalid" << endl;
            return;
        } else {
            Node *node = new Node(data);

            if(index == 0) {
                if(head == nullptr) {
                    head = node;

                } else {
                    node -> next = head;
                    head = node;
                }

            } else {
                Node *aux = head;

                for(int i = 0; i < index - 1; i++) {
                    aux = aux -> next;
                }

                node -> next = aux -> next;
                aux -> next = node;
            }

        }

        length++;
    }

    void insertInSortedList(int data) {
        Node *node = new Node(data);


        if(head == nullptr) {
            head = node;
        } else {
            //Node *prev = nullptr;
            Node *aux = head;

            while(aux -> next && aux -> next -> data < data) {
                aux = aux -> next;
            }

            if(aux == head) {
                node -> next = head;
                head = node;
            } else {
                node -> next = aux -> next;
                aux -> next = node;
            }
        }
    }

    void deleteElement(int index) {
        if(index < 0 || index > length) {
            cout << "It's not possible to delete this element at this index because it's invalid" << endl;
            return;
        }

        if(head == nullptr) {
            cout << "It's not possible to remove an element at this index because the list is empty." << endl;
            return;
        } else {
            Node *aux = head;

            if(index == 0) {
                head = head -> next;
                delete aux;
            } else {
                Node *prev = nullptr;

                for(int i = 0; i < index; i++) {
                    prev = aux;
                    aux = aux -> next;
                }

                prev -> next = aux -> next;
                delete aux;
            }
        }


    }

    bool isSortedList(LinkedList L) {
        if(L.head == nullptr) {
            cout << "List is empty..." << endl;
            return false;
        } else {
            int x = INT_MIN;
            Node *aux = L.head;

            while(aux) {
                if(x < aux -> data) {\
                    x = aux -> data;
                    aux = aux -> next;

                } else {
                    return false;
                }
            }

            return true;
        }
    }

    void removeDuplicates() {
        if(head == nullptr) {
            cout << "List is empty..." << endl;
            return;
        } else {
            Node *prev = head;
            Node *aux = head -> next;

            while(aux) {
                if(prev -> data == aux -> data) {
                    prev -> next = aux -> next;
                    delete aux;
                    aux = prev -> next;
                    length--;
                } else {
                    prev = aux;
                    aux = aux -> next;
                }
            }
        }
    }

    void reverseLinkedListByRevertingElements() {
        if(head == nullptr) {
            cout << "List is empty..." << endl;
        } else {
            Node *aux = head;
            int i = 0;
            int A[length];

            while(aux) {
                A[i] = aux -> data;
                aux = aux -> next;
                i++;
            }

            aux = head;
            i--;

            while(aux) {
                aux -> data = A[i--];
                aux = aux -> next;
            }
        }
    }

    void reverseLinkedListByRevertingLinks() {
        if(head == nullptr) {
            cout << "List is empty..." << endl;
        } else {
            Node *r = nullptr;
            Node *q = nullptr;
            Node *p = head;

            while(p) {
                r = q;
                q = p;
                p = p -> next;

                q -> next = r;
            }

            head = q;


        }
    }

    void _reverseLinkedListByRecursion(Node *q, Node *p) {
        if(p != nullptr) {
            _reverseLinkedListByRecursion(p, p -> next);
            p -> next = q;
        } else {
            head = q;
        }
    }

    void reverseLinkedListByRecursion() {
        if(head == nullptr) {
            cout << "List is empty..." << endl;
        } else {
            Node *aux = nullptr;

            _reverseLinkedListByRecursion(aux, head);
        }
    }

    LinkedList *concat(LinkedList *B) {
        LinkedList *C = new LinkedList();

        C -> length = this -> length + B -> length;
        C -> head = this -> head;

        Node *aux = this -> head;

        while(aux -> next != nullptr) {
            aux = aux -> next;
        }


        B -> head = nullptr;

        return C;
    }

    void mergeLinkedLists(LinkedList *B) {
        Node *first = this -> head;
        Node *second = B -> head;

        if(isSortedList(*this) && isSortedList(*B)) {
            Node *third = nullptr;
            Node *last = nullptr;

            if(first -> data < second -> data) {
                third = last = first;
                first = first -> next;
                third -> next = nullptr;
            } else {
                third = last = second;
                second = second -> next;
                third -> next = nullptr;
            }

            while(first && second) {
                if(first -> data < second -> data) {
                    last -> next = first;
                    last = first;
                    first = first -> next;
                    last -> next = nullptr;
                } else {
                    last -> next = second;
                    last = second;
                    second = second -> next;
                    last -> next = nullptr;
                }
            }

            if(first != nullptr) {
                last -> next = first;
            }

            if(second != nullptr) {
                last -> next = second;
            }
        } else {
            return;
        }
    }

    bool isThereALoop() {
        if(head == nullptr) {
            return false;
        } else {
            Node *p = head;
            Node *q = head;

            do {
                p = p -> next;
                q = q -> next;

                q = q != nullptr ? q -> next : nullptr;
            } while(p && q);

            return p == q ? true : false;
        }
    }

    void print() {
        if(head == nullptr) {
            cout << "Linked List is empty" << endl;
        } else {
            Node *aux;

            aux = head;

            while(aux != nullptr) {
                cout << aux -> data << " -> ";
                aux = aux -> next;
            }

            cout << endl;
        }
    }

    void _printRecursively(Node *p) {
        if(p != nullptr) {
            cout << p -> data << " -> ";
             _printRecursively(p -> next);
        }
    }

    void printRecursively() {

        if(head == nullptr) {
            cout << "Linked List is empty" << endl;
        } else {
            _printRecursively(head);
        }

        cout << endl;
    }

    ~LinkedList() {

    }
};

int main() {
    LinkedList L;
    LinkedList L2;

    //L.push(9);
    //L.push(5);
    //L.push(1);
    //L.push(2);
    //L.push(10);

    L.insert(2, 0);
    L.insert(8, 1);
    L.insert(10, 2);
    L.insert(15, 3);

    L.print();

    //L.deleteElement(4);
    //cout << "Removing duplicates..." << endl;
    //L.removeDuplicates();
    //L.print();

    cout << "Is the list sorted? ";
    L.isSortedList(L) == true ? cout << "Yes" << endl : cout << "No!" << endl;

    //cout << "Reversing list..." << endl;
    //L.reverseLinkedListByRevertingLinks();
    //L.print();

    //cout << "Reversing list..." << endl;
    //L.reverseLinkedListByRecursion();
    //L.print();


    cout << "Linked list lenght: " << L.getLength() << endl;
    cout << "Sum of the elements: " << L.getSum() << endl;
    cout << "Max number of the linked list: " << L.getMax() << endl;
    cout << "Min number of the linked list: " << L.getMin() << endl;

    //cout << "Searching for 2..." << endl;
    //Node* nodeSearch = L.searchByMovingToHead(8);
    //nodeSearch == nullptr ? cout << "Not found" << endl : cout << "Found!" << endl;
    //L.print();

    //L.insert(88, 1);
    //L.print();

    L2.push(4);
    L2.push(7);
    L2.push(12);
    L2.push(14);

    L2.print();

    LinkedList* L3;

    cout << "Merging L and L1: ";
    L.mergeLinkedLists(&L2);
    L.print();

    return 0;
}
