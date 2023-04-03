#include<bits/stdc++.h>
using namespace std;

bool isCycleDFS(int src, unordered_map<int, bool> &visited, int parent, unordered_map<int, list<int>> adj){
    // Mark the current node as visited
    visited[src] = true;

    for(auto neighbour : adj[src]){
        // If an adjacent vertex is not visited,
        // then recur for that adjacent
        if(!visited[neighbour]){
            bool ans = isCycleDFS(neighbour, visited, src, adj);
            if(ans == true){
                return true;
            }
        }
        // If an adjacent vertex is visited and
        // is not parent of current vertex,
        // then there exists a cycle in the graph.
        else if(neighbour != parent){
            return true;
        }
    }

    return false;
}

string cycleDetection(int v, int e, vector<vector<int>> &edges){
    //createing adjacency list
    unordered_map<int, list<int>> adj;
    for(int i = 0; i < e; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //to handle diconnected graphs
    unordered_map<int, bool> visited;

    for(int i = 0; i < v; i++){
        if(!visited[i]){
            bool ans = isCycleDFS(i, visited, -1, adj);
            if(ans == 1){
                return "YES";
            }
        }
    }
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

    string ans = cycleDetection(V, E, edges);

    cout<<ans<<endl;

    return 0;
}