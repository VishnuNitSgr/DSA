#include<iostream>
#include<stack>
using namespace std;

bool checkSorted(stack<int>& s,int element1){
    if(s.empty()) return true;
    int element2=s.top();
    s.pop();
    if(element2<element1){
        bool nextAns=checkSorted(s,element2);
        return nextAns;

    }
    else
    return false;
}

int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(20);
    st.push(5);
    st.push(6);
    
    int element1=INT_MAX;
    cout<<checkSorted(st,element1)<<endl;

    return 0;
}
