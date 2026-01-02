#include<iostream>
#include<stack>
using namespace std;
void insertAtBottom(stack<int>& s,int val){
if(s.empty()){
    s.push(val);
    return;
}
int topElement=s.top();
s.pop();
insertAtBottom(s,val);
s.push(topElement);

}
int main(){
    stack<int>st;
    st.push(1); 
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    
    int value=13;
    insertAtBottom(st,value);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();

    }cout<<endl;
    return 0;
}