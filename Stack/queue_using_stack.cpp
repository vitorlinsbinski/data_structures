#include <iostream>
#include <stack>

using namespace std;

class QueueUsingStack {
private:
    stack<int> S1;
    stack<int> S2;

public:
    QueueUsingStack() {

    }

    void enqueue(int value) {
        S1.push(value);
    }

    void dequeue() {
        if(S2.empty() && S1.empty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        if(!S2.empty()) {
            S2.pop();
        } else {
            while(!S1.empty()) {
                S2.push(S1.top());
                S1.pop();
            }

            if (!S2.empty()) {
                S2.pop();
            }
        }
    }

    void display() {
        if(S1.empty() && S2.empty()) {
            cout << "Queue is empty!!!" << endl;
            return;
        }

        stack<int> S3;
        stack<int> tempS2 = S2;
        stack<int> tempS1 = S1;

        while(!tempS2.empty()) {
            cout << tempS2.top() << ", ";
            tempS2.pop();
        }

        while(!tempS1.empty()) {
            S3.push(tempS1.top());
            tempS1.pop();
        }

        while(!S3.empty()) {
            cout << S3.top() << ", ";
            S3.pop();
        }

        cout << endl;
    }

    ~QueueUsingStack() {}

};

int main() {
    QueueUsingStack q;

    q.enqueue(6);
    q.enqueue(3);
    q.enqueue(9);
    q.enqueue(5);
    q.enqueue(4);
    q.enqueue(2);
    q.enqueue(8);
    q.enqueue(12);
    q.enqueue(10);

    q.display();

    q.dequeue();

    q.display();



    return 0;
}
