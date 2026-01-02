#include<iostream>
#include<algorithm>
using namespace std;
class twoStack{
    public:
    int* arr;
    int size;
    int top1;
    int top2;
    twoStack(int capacity){
        size=capacity;
        top1=-1;
        top2=size;
        arr=new int[size];
    }
    void push1(int element){
       if((top2-top1==1)){
        cout<<"stack overflow"<<endl;
       }
       else{
        top1++;
        arr[top1]=element;
       }
    }
    void push2(int element){
        if((top2-top1==1)){
         cout<<"stack overflow"<<endl;
        }
        else{
         top2--;
         arr[top2]=element;
        }
     }
     void pop1(){
        if(top1==-1){
            cout<<"stack underflow"<<endl;
        }
        else{
            arr[top1]=-1;
            top1--;
        }
     }
     void pop2(){
        if(top2==size){
            cout<<"stack underflow"<<endl;

        }
        else{
            arr[top2]=-1;
            top2--;
        }
     }
     void print(){
        for (int i = 0; i < size; i++)
        {
            cout<<arr[i]<<" ";
        }cout<<endl;
     }
};

int main(){
    twoStack s(5);
    s.push1(10);
    s.push1(20);
    s.push1(30);
    s.print();
    s.push2(40);
    s.push2(50);
    s.print();
    
    
    s.push1(60);
    s.print();
    s.pop1();
    s.push1(60);
    s.print();

    
    return 0;
}