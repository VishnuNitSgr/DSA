#include<iostream>
#include<stack>
using namespace std;
int main(){
    string s="vishnu";
    stack<char>st;
    //insertion of character into the stack
    for(int i=0;i<s.length();i++){
        st.push(s[i]);
    }
    //retrieval of character from the stack
    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }

    return 0;

}