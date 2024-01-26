#include <iostream>

using namespace std;

class Queue {
private:
    int size;
    int *E;
    int f;
    int r;

public:
    Queue(int size) {
        this->size = size;
        this -> E = new int[size];
        this -> f = -1;
        this -> r = -1;
    }

    bool isEmpty() {
        return f == r;
    }

    bool isFull() {
        return r == size - 1;
    }

    void enqueue(int value) {
        if(!isFull()) {
            r++;
            E[r] = value;
        } else {
            cout << "Queue is full, you cannot insert any element." << endl;
            return;
        }
    }

    void dequeue() {
        if(!isEmpty()) {
            f++;

            if(isEmpty()) {
                f = -1;
                r = -1;
            }
        } else {
            cout << "Queue is empty, it's not possible to remove any elements." << endl;
            return;
        }
    }

    void display() {
        if(!isEmpty()) {
            cout << "Start: ";
            for(int i = f + 1; i <= r; i++) {
                cout << E[i] << " | ";
            }
        } else {
            cout << "Queue is empty, there is nothing to display." << endl;
            return;
        }

        cout << endl;
    }

    ~Queue() {
        delete[] E;
    }
};

int main() {
    Queue myQueue(5);

    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);
    myQueue.enqueue(4);
    myQueue.enqueue(5);

    myQueue.display();

    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.dequeue();

    myQueue.display();

    myQueue.enqueue(3);
    myQueue.enqueue(4);
    myQueue.enqueue(5);
    myQueue.enqueue(6);
    myQueue.enqueue(7);

    myQueue.display();


    return 0;
}
