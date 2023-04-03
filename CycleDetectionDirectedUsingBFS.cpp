#include<bits/stdc++.h>
using namespace std;

bool isCyclic(int vertex, int edge, vector<vector<int>> edges){
    // create adjacency list
    unordered_map<int, list<int>> adj;

    for(int i = 0; i < edge; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    //create indegree vector
    vector<int> indegree(vertex);

    for(auto i : adj){
        for(auto j : i.second){
            indegree[j]++;
        }
    }

    int cnt = 0;

    queue<int> q;


    for(int i = 0; i < vertex; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int front = q.front();
        q.pop();

        cnt++;


        for(auto neighbour : adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour] == 0){
                q.push(neighbour);
            }
        }
    }

    return !(cnt == vertex);

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


//Approach 2

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        //create indegree vector
    vector<int> indegree(V);

    for(int i = 0; i < V; i++){
        for(auto j : adj[i]){
            indegree[j]++;
        }
    }

    int cnt = 0;

    queue<int> q;


    for(int i = 0; i < V; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int front = q.front();
        q.pop();

        cnt++;


        for(auto neighbour : adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour] == 0){
                q.push(neighbour);
            }
        }
    }

    return !(cnt == V);
    }
};

