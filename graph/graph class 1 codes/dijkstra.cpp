#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <climits>
#include <queue>
#include <set>
using namespace std;

class graph {
public:
    unordered_map<int, list<pair<int,int>>> adj;

    void addEdge(int u,int v,int wt,bool direction){
        adj[u].push_back(make_pair(v,wt));
        if(direction==0){ // 0 means undirected
            adj[v].push_back(make_pair(u,wt));
        }
    }

    void print(){
        for(auto &i:adj){
            cout<<i.first<<"->";
            for(auto &j:i.second){
                cout<<"("<<j.first<<","<<j.second<<")";
            }
            cout<<endl;
        }
    }

    void shortestDisDijkstra(int src,int des){
        // pick a size bigger than max node index
        vector<int> dist(6,INT_MAX);
        set<pair<int,int>> s; // (dist,node)
        dist[src]=0;
        s.insert(make_pair(0,src));

        while(!s.empty()){
            auto topElement=*s.begin();
            int node=topElement.second;
            int nodeDist=topElement.first;
            s.erase(s.begin());

            // neighbours
            for(auto& nbr:adj[node]){
                int nbrNode=nbr.first;
                int edgeWeight=nbr.second;
                if(nodeDist+edgeWeight<dist[nbrNode]){
                    // update in set also
                    auto result=s.find({dist[nbrNode],nbrNode});
                    if(result!=s.end()){
                        s.erase(result);
                    }
                    dist[nbrNode]=edgeWeight+nodeDist;
                    s.insert({dist[nbrNode],nbrNode});
                }
            }
        }

        cout<<"printing the result"<<endl;
        for(int i=0;i<dist.size();i++){
            if(dist[i]==INT_MAX) cout<<"Distance from "<<src<<" to "<<i<<" is infinite "<<endl;
            else cout<<"Distance from "<<src<<" to "<<i<<" is "<<dist[i]<<endl;
        }
    }
    void bellmenFord(int src,int des){
        vector<int>dist(des,INT_MAX);
        dist[src]=0;
        // n-1 times loop chalana hai 
        for(int i=0;i<des-1;i++){
            //har edge par jaana hai aur relaxation krna hai
            for(auto a:adj)
            {
                for(auto b:a.second){
                    // a->pair<int,list<pair<int,int>>>
                    // and j.second ek list hai jisme pairs hai /
                    // b.first->node v
                    // b.second->weight
                    int u=a.first;
                    int v=b.first;
                    int wt=b.second; 
                    if(dist[u]!=INT_MAX && dist[u]+wt<dist[v]){
                        dist[v]=dist[u]+wt;
                    }

                }
            }
        }
        for(int i=0;i<des;i++){
            // if(dist[i]==INT_MAX) cout<<"Distance from "<<src<<" to "<<i<<" is infinite "<<endl;
             cout<<"Distance from "<<src<<" to "<<i<<" is "<<dist[i]<<endl;
        } 
    }void floydWarshall(int n) {
    // initialize distance matrix
    vector<vector<int>> dist(n, vector<int>(n, 1e9));

    // diagonal = 0
    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }

    // copy all distances from graph
    for (auto &a : adj) {
        for (auto &b : a.second) {
            int u = a.first;
            int v = b.first;
            int wt = b.second;
            dist[u][v] = wt;
        }
    }

    // main Floyd–Warshall logic
    for (int k = 0; k < n; k++) {          // helper
        for (int i = 0; i < n; i++) {      // src
            for (int j = 0; j < n; j++) {  // des
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // print result
    cout << "Printing the result" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == 1e9) cout << "INF ";
            else cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

};


int main(){
    graph g;
    // g.addEdge(0,1,-1,1);
    // g.addEdge(0,2,4,1);
    // g.addEdge(1,2,3,1);
    // g.addEdge(1,3,2,1);
    // g.addEdge(1,4,2,1);
    // g.addEdge(3,1,1,1);
    // g.addEdge(3,2,5,1);
    // g.addEdge(4,3,-3,1);

    g.addEdge(0,2,-2,1);
    g.addEdge(2,3,2,1);
    g.addEdge(3,1,-1,1);
    g.addEdge(1,0,4,1);
    g.addEdge(1,3,2,1);
    g.print();
    // g.shortestDisDijkstra(0,5);
    g.bellmenFord(0,5);
    return 0;
}
