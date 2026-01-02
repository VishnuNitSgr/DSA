#include<iostream>
#include<stack>
#include<queue>
using namespace std;
// void queueRev(queue<int>& q){
//    stack<int>st;
//    while(!q.empty()){
//     int element=q.front();
//     q.pop();
//     st.push(element);
//    }

//    while(!st.empty()){
//     int top=st.top();
//     st.pop();
//     q.push(top);
//    }
// }

void queueRevRec(queue<int>& q){
    if(q.empty()){
        return;
    }
    int front=q.front();
    q.pop();
    queueRevRec(q);
    q.push(front);
}
int main(){
    queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    
    queueRevRec(q);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}