#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int>& s,int val){
    if(s.empty()){
        s.push(val);
        return;
    }
    int topEle=s.top();
    s.pop();
    insertAtBottom(s,val);
    s.push(topEle);
}
void reverseStack(stack<int>& s){
    if(s.empty())return;
    int topEle=s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s,topEle);

    
}
void print(stack<int>& s){
    while(!s.empty()){
    cout<<s.top()<<" ";
    s.pop();
    }
    
}
int main(){
    stack<int>s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
   
    cout<<"reversed stack-->";
    reverseStack(s);
    
    print(s);
    return 0;
}
