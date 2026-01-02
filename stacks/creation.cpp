#include<iostream>
using namespace std;
class Stack{
    public:
    
    int top;//it will tell me the index of the top element ye top wale element ke liye index ka kaam karegi
    int size;
    int* arr;
    Stack(int capacity){
        top=-1;
        size=capacity;
        arr=new int[size];
    }
    void push(int element){
        if(top==size-1){
            cout<<"stack overflowed"<<endl;
        }
        else{
            top++;
            arr[top]=element;
        }

    }
    void pop(){
        if(top==-1){
            cout<<"stack underflow"<<endl;
        }
        else{
            arr[top]=-1;
            top--;
        }

    }
    int getSize(){
        return top+1;

    }
    bool isEmpty(){
        if(top==-1)return true;
        else return false;

    }
    int getTop(){
        if(top==-1)return -1;
        else return arr[top];

    }
    void print(){
        for (int i = 0; i < size; i++)
        {
            cout<<arr[i]<<" ";
        }cout<<endl;
        
    }

};

int main()
{
    Stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.pop();
    s.pop();
    s.push(70);
    cout<<s.getTop()<<endl;
    cout<<s.getSize()<<endl;
    cout<<s.isEmpty()<<endl;
    s.print();

    
}