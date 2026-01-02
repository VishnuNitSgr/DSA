#include<iostream>
using namespace std;
class deCircularQueue {
    int *arr;
    int front, rear;
    int size;
public:
    deCircularQueue(int size) {
        arr = new int[size];
        front = -1;
        rear = -1;
        this->size = size;
    }
    void pushFront(int element){
        if((front==0&&rear==size-1)||(rear==front-1))
        cout<<"stack overflowed"<<endl;
        else if(front==-1 && rear==-1){
            front++,rear++;
            arr[rear]=element;
        }
        else if(front==0 && rear>0){
            front=size-1;
            arr[front]=element;
        }
        else {
            front--;
            arr[front]=element;
        }

    }
    void pushBack(int element){

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
    void popFront(){

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
    void popBack(){
        if(front==-1&& rear==-1)cout<<"stack underflow"<<endl;
    
        else if(front==rear){
            arr[rear]=-1;
            front=-1;
            rear=-1;
        }
        else if(rear==0){
           
            arr[rear]=-1;
            rear=size-1;
        }
        else{
            arr[rear]=-1;
            rear--;
        }

    }
    void print(){
        for(int i=0;i<=size;i++){
            cout<<arr[i]<<" ";
        }
    }
    }; 
    int main(){
        deCircularQueue q(5);
        q.pushBack(10);
        q.pushBack(20);
        q.pushFront(5);
        q.pushFront(1);
        q.print();
     
       
        q.popFront();
        q.print();
        q.popBack();
        q.print();
  
        return 0;
    }     