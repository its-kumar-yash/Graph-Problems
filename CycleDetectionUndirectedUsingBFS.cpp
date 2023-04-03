#include<bits/stdc++.h>
using namespace std;

bool isCycleBFS(int src, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj){
    //create map to track the parent node
    unordered_map<int, int> parent;

    parent[src] = -1;
    visited[src] = true;

    queue<int> q;
    q.push(src);

    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(auto neighbor : adj[front]){
            //target condition
            if(visited[neighbor] == true && neighbor != parent[front]){
                return true;
            }

            else if(!visited[neighbor]){
                q.push(neighbor);
                visited[neighbor] = true;
                parent[neighbor] = front;
            }
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
            bool ans = isCycleBFS(i, visited, adj);
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