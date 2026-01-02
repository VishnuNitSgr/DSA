#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
void solve(vector<int>&arr, stack<int>&s, vector<int>&ans){
    int n=arr.size();
    for(int i=0;i<n;i++){
        int element=arr[i];
        while(s.top()>element){
            s.pop();
        }
        ans.push_back(s.top());
        s.push(element);
    }
}
int main(){
    vector<int>v;
    v.push_back(8);
    v.push_back(4);
    v.push_back(6);
    v.push_back(2);
    v.push_back(3);

    stack<int>s;
    s.push(-1);  // sentinel value
    vector<int>ans;

    solve(v, s, ans);
   
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}