#include<bits/stdc++.h>
using namespace std;

void dfs(int src, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, stack<int> &st){
    visited[src] = true;

    for(auto adjNode : adj[src]){
        if(!visited[adjNode]){
            dfs(adjNode, adj, visited, st);
        }
    }

    //after returning from every call push node into the stack
    st.push(src);
}

vector<int> topologicalSort(int vertex, int edge, vector<vector<int>> &edges){
    //create adjacency list
    unordered_map<int, list<int>> adj;

    for(int i = 0; i < edge; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    //call dfs for all vertices
    unordered_map<int, bool> visited;
    stack<int> st; // to store the topological sort order

    for(int i = 0; i < vertex; i++){
        if(!visited[i]){
            dfs(i, adj, visited, st);
        }
    }

    //after completing the dfs traversal stack contains the topological sort order
    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
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

    vector<int> ans = topologicalSort(V, E, edges);

    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}