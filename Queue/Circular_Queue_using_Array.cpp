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
        this -> f = 0;
        this -> r = 0;
    }

    int getNextPosition(int x) {
        return (x + 1) % size;
    }

    bool isEmpty() {
        return f == r;
    }

    bool isFull() {
        return getNextPosition(r) == f;
    }

    void enqueue(int value) {
        if(!isFull()) {
            r = getNextPosition(r);
            cout << "r: " << r << endl;
            E[r] = value;
        } else {
            cout << "Queue is full, you cannot insert any element." << endl;
            return;
        }
    }

    void dequeue() {
        if(!isEmpty()) {
            f = getNextPosition(f);
        } else {
            cout << "Queue is empty, it's not possible to remove any elements." << endl;
            return;
        }
    }

    void display() {
        if(!isEmpty()) {
            cout << "Start: ";

            int i = f;

            do {
                i = getNextPosition(i);
                cout << E[i] << " | ";
            } while(i != r);

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

    myQueue.display();

    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.dequeue();

    myQueue.display();

    myQueue.enqueue(3);
    myQueue.enqueue(4);
    myQueue.enqueue(5);
    myQueue.enqueue(6);

    myQueue.display();

    myQueue.dequeue();
    myQueue.display();

    myQueue.dequeue();
    myQueue.display();

    myQueue.dequeue();
    myQueue.display();

    myQueue.dequeue();
    myQueue.display();



    return 0;
}
