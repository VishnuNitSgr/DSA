#include<iostream>
#include<vector>
#include<stack>
#include<algorithm> // for reverse
using namespace std;

void solve(vector<int>&arr, stack<int>&s, vector<int>&ans){
    int n = arr.size();  // FIX: loop should run based on array size
    for(int i = n - 1; i >= 0; i--){
        int element = arr[i];
        while(s.top() >= element){
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

    // FIX: reverse to maintain left-to-right output order
    reverse(ans.begin(), ans.end());

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
}
