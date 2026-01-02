#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;
    int n;
    int front, rear;

public:
    Queue(int size) {
        n = size;
        arr = new int[n];
        front = -1;
        rear = -1;
    }

    void push(int element) {
        if (rear == n - 1)
            cout << "Overflow" << endl;
        else if (front == -1 && rear == -1) {
            front = rear = 0;
            arr[rear] = element;
        } else {
            rear++;
            arr[rear] = element;
        }
    }

    void pop() {
        if (front == -1 && rear == -1)
            cout << "Underflow" << endl;
        else if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
    }

    int getFront() {
        if (front == -1) {
            cout << "No front element exists" << endl;
            return -1;
        }
        return arr[front];
    }

    int getRear() {
        if (rear == -1) {
            cout << "No rear element exists" << endl;
            return -1;
        }
        return arr[rear];
    }

    int getSize() {
        if (front == -1) return 0;
        return rear - front + 1;
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    ~Queue() {
        delete[] arr;
    }
};

int main() {
    Queue q(5);
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.pop();

    cout << "Front: " << q.getFront() << endl;
    cout << "Rear: " << q.getRear() << endl;
    cout << "Size: " << q.getSize() << endl;
    cout << "Empty: " << (q.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
