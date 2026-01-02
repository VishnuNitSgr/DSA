#include<iostream>
#include<stack>
using namespace std;

void sortedInsert(stack<int>& s,int val){
   
    if (s.empty() || s.top() < val)
    {
        s.push(val);
        return;
    }

    int topEle = s.top();
    s.pop();
    sortedInsert(s, val);
    s.push(topEle);
}

void print(stack<int>& s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}

int main(){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    int val = 23;

    
    sortedInsert(s, val);
    cout << endl;

    print(s);  
    return 0;
}
