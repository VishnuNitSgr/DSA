#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<limits>

using namespace std;
class Queue{
    public:
    int* arr;
    int front,rear;
    int size;
    Queue(int size){
        arr=new int[size];
        front=-1,rear=-1;
        this->size=size;
    }
    void push(int element){
        if((front==0&&rear==size-1)||(rear==front-1))
        cout<<"stack overflowed"<<endl;
        else if(front==-1 && rear==-1){
            front++,rear++;
            arr[rear]=element;
        }
        else if(front>0&& rear==size-1){
            rear=0;
            arr[rear]=element;
        }
        else{
            rear++;
            arr[rear]=element;


    }
}
    void pop(){
        if(front==-1&& rear==-1)cout<<"stack underflow"<<endl;
        else if(front==rear){
            arr[front]=-1;
            front=-1;
            rear=-1;
        }
        else if(front==size-1){
            
            arr[front]=-1;
            front=0;
        }
        else{
            arr[front]=-1;
            front++;
        }

    }
    int getFront(){
        return arr[front];

    }
    int getSize(){
        return (rear>=front)?(rear-front+1):(size-front+rear+1);

    }
    bool isEmpty(){
        if(front==-1 && rear==-1){
        return true;}
        return false;

    }
    void print(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
}
};
int main(){
    Queue q(5);
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.pop();
    q.print();
    cout<<q.getFront()<<endl;
    cout<<q.getSize()<<endl;
    cout<<q.isEmpty()<<endl;
}