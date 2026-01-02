#include <iostream>
using namespace std;

class dequeue {
private:
    int* arr;
    int n;
    int front, rear;

public:
    dequeue(int size) {
        n = size;
        arr = new int[n];
        front = n/2;
        rear = n/2-1;
    }
    void pushFront(int element){
        if(front==0){
            cout<<"stack overflowed"<<endl;
        }
        else if(front==-1 && rear==-1){
            front++,rear++;
            arr[front]=element;
        }
        else {
            front--;
            arr[front] = element;
        }

    }
    void pushBack(int element){
        if(rear==n-1){
            cout<<"stack overflowed"<<endl;
            
        }

        else if(front==-1 && rear==-1){
            rear=front=0;
            arr[rear]=element;
        }
        else {
            rear++;
            arr[rear] = element;
        }
    }

    void popFront(){
        if(front==-1 && rear==-1){
            cout<<"stack underflow"<<endl;
        }
        else if(front==rear){
            arr[front] = 0;
            front=rear=-1;
        }
        else{
            
            arr[front] =0;
            front++;
        }

    }
    void popBack(){


        if(front==-1 && rear==-1){
            cout<<"stack underflow"<<endl;
        }
        else if(front==rear){
            arr[rear]=0;
            front=rear=-1;
            
        }
        else{
            arr[rear]=0;
            rear--;
        }
    }
  void print () {
    // if (front > rear) {
    //     cout << "Deque is empty" << endl;
    //     return;
    // }
    for (int i = front; i <= rear; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

};

int main(){
    dequeue dq(4);
    dq.pushFront(10);
    dq.pushBack(20);
    dq.pushFront(30);
    dq.pushBack(40);
    dq.popFront();
    dq.popBack();
    dq.print();
    return 0;
}