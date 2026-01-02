#include<iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <climits>
#include <queue>
#include <stack>
#include <set>
using namespace std;
class graph{
    public:
    unordered_map<int,list<int> >adj;
    void addEdge(int u,int v,bool direction){
        
        if(direction==1){
            adj[u].push_back(v);
        }
        else{
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    void print(int n){
        for(int i=0;i<n;i++){
            cout<<i<<"->"<<"{";
            for(auto j:adj[i])
            cout<<j<<",";
            cout<<"}"<<endl;
        }
    }
    void dfs(unordered_map<int,list<int>>&transpose,int src,unordered_map<int,bool>&visited){
        visited[src]=true;
        cout<<src<<" ";
        for(auto nbr:adj[src]){
            if(!visited[nbr]){
                dfs(transpose,nbr,visited);
            }
        }
    }
    void topoSortDfs(stack<int>&s,int node,unordered_map<int,bool>&visited){
       visited[node]=true;
       for(auto nbr:adj[node]){
        if(!visited[nbr]){
            topoSortDfs(s,nbr,visited);
        }

       }
       s.push(node);
}
 int countSCC(int n){
        // find topo ordereing
        stack<int>s;
        unordered_map<int,bool>visited;
       
       for(int i=0;i<7;i++){
        if(!visited[i]){
            topoSortDfs(s,i,visited);
        }
    }
    // edges ko reverse krna hai
    unordered_map<int,list<int>>transpose;
    for(auto i:adj){
        for(auto j:i.second){
            int u=i.first;
            int v=j;
            transpose[v].push_back(u);
        }
    }
    // dfs call ->count->scc
    int count=0;
    unordered_map<int,bool>visit;
    while(!s.empty()){
        int top=s.top();
        s.pop();
        if(!visit[top]){
            count++;
            dfs(transpose,top,visit);
        }
    }
    return count;
        
    }
};
int main(){
    graph g;
    g.addEdge(0,3,1);
    g.addEdge(3,2,1);
    g.addEdge(2,1,1);
    g.addEdge(1,0,1);
    g.addEdge(2,4,1);
    g.addEdge(4,5,1);
    g.addEdge(5,6,1);
    g.addEdge(6,4,1);
    g.addEdge(6,7,1);
    g.print(5);
    stack<int>s;
    unordered_map<int,bool>visited;
    for(int i=0;i<7;i++){
        if(!visited[i]){
            g.topoSortDfs(s,i,visited);
        }
    }
    cout << "\nStrongly Connected Components:\n";
    int sccCount = g.countSCC(7);
    cout << "\nTotal SCCs: " << sccCount << endl;
    return 0;
    // cout<<"topo sort using dfs"<<endl;
    // while(!s.empty()){
    //     cout<<s.top()<<" ";
    //     s.pop();
    // }
}