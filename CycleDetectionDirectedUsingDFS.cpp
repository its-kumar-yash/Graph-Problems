#include<bits/stdc++.h>
using namespace std;

bool cycleDFS(int src, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, unordered_map<int, bool> &recurStack){
    visited[src] = true;
    recurStack[src] = true;

    for(auto adjNode : adj[src]){
        if(!visited[adjNode]){
            bool cycleFound = cycleDFS(adjNode, adj, visited, recurStack);
            if(cycleFound){
                return true;
            }
        }
        else{
            //visted and recurStack both are true
            if(recurStack[adjNode]  == true){
                return true;
            }
        }
    }

    recurStack[src] = false;

    return false;
}


bool isCyclic(int v, int e, vector<vector<int>> &edges){
    //create adjacency list
    unordered_map<int, list<int>> adj;
    
    for(int i = 0; i < e; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    //create visited map
    unordered_map<int, bool> visited;

    //create recursion stack visited data structure
    unordered_map<int, bool> recurStack;


    for(int i = 0; i < v; i++){
        if(!visited[i]){
            bool ans = cycleDFS(i, adj, visited, recurStack);
            if(ans == true){
                return true;
            }
        }
    }

    return false;
}

int main(){
    // v - no. of vertices
    // e - no. of edges
    int V, E;
    cin>> V>> E;

    vector<vector<int>> edges;

    for(int i = 0; i < E; i++){
        int u, v;
        cin>>u>>v;

        edges.push_back({u, v});
    }

    bool ans = isCyclic(V, E, edges);

    (ans == true) ? cout<<"YES"<<endl : cout<<"NO"<<endl;

    return 0;
}