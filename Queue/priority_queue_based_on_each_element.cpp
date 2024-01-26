#include <iostream>
#include <queue>
#include <limits>

using namespace std;

class PriorityQueue {
private:
    int *queue;
    int size;
    int length;

public:
    PriorityQueue(int size) {
        this -> size = size;
        queue = new int[this -> size];
        this -> length = 0;
    }

    void swap(int &x, int &y) {
        int temp = x;
        x = y;
        y = temp;
    }

    void enqueueByOrder(int value) {
        if(length < size) {
            queue[length++] = value;
        } else  {
            cout << "Priority queue is full!" << endl;
        }
    }

    void dequeueBySearching() {

        if(length != 0) {
            cout << "Pop: ";

            while(length != 0) {
                int maxPriority = numeric_limits<int>::max();
                int maxPriorityIndex = -1;

                for(int i = 0; i < length; i++) {
                    if(queue[i] < maxPriority) {
                        maxPriority = queue[i];
                        maxPriorityIndex = i;
                    }
                }

                cout << maxPriority << ", ";

                for(int j = maxPriorityIndex; j < length; j++) {
                    queue[j] = queue[j + 1];
                }

                length--;
            }

        }
    }

    void enqueueByPriority(int value) {
        if(length < size) {
            queue[length++] = value;

            int i = length - 1;

            while(i > 0 && value > queue[i - 1]) {
                queue[i] = queue[i - 1];
                i--;
            }

            queue[i] = value;

        } else  {
            cout << "Priority queue is full!" << endl;
        }
    }

    void dequeueAtTheEnd() {
        if(length != 0) {
            cout << "Pop: ";

            while(length != 0) {
                cout << queue[length - 1] << ", ";

                length--;
            }

            cout << endl;
        } else {
            cout << "Priority queue is empty!" << endl;
            return;
        }

    }

    void display() {
        cout << "Display: ";

        for(int i = 0; i < length; i++) {
            cout << queue[i] << ",";
        }

        cout << endl;
    }

    ~PriorityQueue() {
        delete[] queue;
    }
};

int main() {
    PriorityQueue q(10);

    q.enqueueByPriority(6);
    q.enqueueByPriority(8);
    q.enqueueByPriority(3);
    q.enqueueByPriority(10);
    q.enqueueByPriority(15);
    q.enqueueByPriority(2);
    q.enqueueByPriority(9);

    q.display();

    q.dequeueAtTheEnd();

    return 0;
}
