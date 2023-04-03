// Given an undirected and disconnected graph G(V, E), containing 'V' vertices and 'E' edges, the information about edges is given using 'GRAPH' matrix, where i-th edge is between GRAPH[i][0] and GRAPH[i][1]. print its DFS traversal.

#include<bits/stdc++.h>
using namespace std;

void dfs(int source, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjList, vector<int> &component){
    component.push_back(source);
    visited[source] = true;
    
    //for every connected node 
    for(auto i : adjList[source]){
        if(!visited[i]){
            dfs(i, visited, adjList, component);
        }
    }
}



vector<vector<int>> DFS(int vertex, vector<vector<int>> &edges){
    //step 1 - creating adjacency list
    unordered_map<int, list<int>> adjList;

    for(int i = 0; i < edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    //create a visited map
    unordered_map<int, bool> visited;

    // to store answer
    vector<vector<int>> ans;

    //now traverse all components of the graph
    for(int i = 0; i < vertex; i++){
        //if not visited, make dfs call
        if(!visited[i]){
            vector<int> component;
            dfs(i, visited, adjList, component);
            ans.push_back(component);
        }
    }

    return ans;
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

    vector<vector<int>> output = DFS(V, edges);

    for(int i = 0; i <output.size(); i++){
        for(int j = 0; j < output[i].size(); j++){
            cout<<output[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}