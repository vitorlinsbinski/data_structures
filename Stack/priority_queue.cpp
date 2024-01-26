#include <iostream>
#include <queue>
#include <map>

using namespace std;

class PriorityQueue {
private:
    queue<char> *queues;
    int n;
    map<char, int> priorityMap = {
        {'A', 1}, {'B', 1}, {'C', 2},
        {'D', 3}, {'E', 2}, {'F', 1},
        {'G', 2}, {'H', 3}, {'I', 2},
        {'J', 2},
    };

public:
    PriorityQueue() {
        this -> n = 3;
        queues = new queue<char>[this -> n];
    }

    void enqueue(char ch) {
        int priorityIndex = priorityMap[ch] - 1;

        queues[priorityIndex].push(ch);
    }

    void dequeue() {
        cout << "Pop: ";
        for(int i = 0; i < n; i++) {
            while(!queues[i].empty()) {
                cout << queues[i].front() << ", ";
                queues[i].pop();
            }
        }

        cout << endl;
    }

    void display() {
        for (int i = 0; i < n; ++i) {
            cout << "Queue " << i + 1 << ": ";

            if (!queues[i].empty()) {
                queue<char> tempQueue = queues[i];
                while (!tempQueue.empty()) {
                    cout << tempQueue.front() << " ";
                    tempQueue.pop();
                }
            } else {
                cout << "Empty";
            }

            cout << endl;
        }
    }


    ~PriorityQueue() {
        delete[] queues;
    }
};

int main() {
    PriorityQueue q;

    q.enqueue('A');
    q.enqueue('B');
    q.enqueue('C');
    q.enqueue('D');
    q.enqueue('E');
    q.enqueue('F');
    q.enqueue('G');
    q.enqueue('H');
    q.enqueue('I');
    q.enqueue('J');

    q.display();

    q.dequeue();
    q.display();

    return 0;
}
