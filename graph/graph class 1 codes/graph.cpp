#include<iostream>
#include <list>
#include<unordered_map>
#include <queue>  
#include<stack>       
#include <vector>        
#include <algorithm>     
using namespace std;

class Graph {
public:
    unordered_map<int,list<int>> adj;

    void addEdge(int u,int v,bool direction){
        
        if(direction == 0){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        else{
            adj[u].push_back(v);
        } 
    }

    void printAdjList(int n){
        for(int i=0;i<n;i++){
            cout<<i<<": {";
            for(auto j:adj[i]){
                cout<<j<<" ";
            }
            cout<<"}"<<endl;
        }
    }

   
    void shortestPathBfs(int src,int des){
        unordered_map<int,bool> visited;
        unordered_map<int,int> parent;
        queue<int> q;
        visited[src]=true;
        q.push(src);           
        parent[src]=-1;

        while(!q.empty()){
            int frontNode=q.front();
            q.pop();
            for(auto nbr:adj[frontNode]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr]=true;
                    parent[nbr]=frontNode;
                }
            }
        }

        if(!visited[des]){ 
            cout << "No path from " << src << " to " << des << endl;
            return;
        }

        vector<int>path;
        int node=des;          
        while(node!=-1){
            path.push_back(node);
            node=parent[node];
        }
        reverse(path.begin(),path.end());
        for(auto i:path) cout<<i<<" ";
        cout<<endl;
    }
};
void topoDfs(int src,stack<int>&st,unordered_map<int,bool>&visited){
    unordered_map<int,bool>visited;
visited[src]=true;
for(auto&nbr:adj[src]){
    if(!visited[nbr]){
        topoDfs(int src,topoOrder,visited);
    }
}
st.push(src);
    
}
void shortestPathDfs(int src){
   

}

int main(){
    Graph g;
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(2,3,0);
    g.addEdge(2,4,0);
    g.addEdge(4,5,0);
    g.addEdge(5,3,0);

    int n = 6; 
    g.printAdjList(n);

   
    int src,des;
    cout<<"Enter source vertex: ";
    cin>>src;
    cout<<"Enter destination vertex: ";
    cin>>des;

    g.shortestPathBfs (src,des);
    return 0;
}
