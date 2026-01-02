#include<iostream>
#include<queue>
#include<stack>
using namespace std;
void reverseKGrp(queue<int> &q ,int k,int count){
   if(count>=k){
    stack<int>st;
    for(int i=0;i<k;i++){
        int val=q.front();
        q.pop();
        st.push(val);
    }
    while(!st.empty()){
        int element=st.top();
        q.push(element);
        st.pop();
    }
    reverseKGrp(q,k,count-k);

   }
   else {
    for(int i=0;i<count;i++){
        int val=q.front();
        q.pop();
        q.push(val);
    }

   }



}
int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    // q.push(6);
    // q.push(7);
    // q.push(8);
    // q.push(9);
    // q.push(10);
    cout<<"enter the value of k: ";
    int k;
    cin>>k;
    int count=q.size();
    //it tracks the. no of elements to reverse
    reverseKGrp(q,k,count);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }

}