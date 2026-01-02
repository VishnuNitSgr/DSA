#include<iostream>
#include<stack>
using namespace std;
void printMiddle(stack<int>& s,int count){
    if(count==0){
         cout<<s.top()<<" ";
         return;
    }
    int topEle=s.top();
    s.pop();
    count--;
    printMiddle(s,count);

    s.push(topEle);
    
}
int main(){
    stack<int>st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    int count=st.size()/2;
    printMiddle(st,count);
    return 0;
}