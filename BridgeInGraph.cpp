#include<bits/stdc++.h>
using namespace std;

void dfs(int src, int parent, int timer, vector<int> &disc, vector<int> &low, vector<vector<int>> &ans, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited){
    visited[src] = true;

    //increment the timer
    disc[src] = low[src] = timer++;

    for(auto neighbor : adj[src]){
        
        if(neighbor == parent){
            continue;
        }
        if(!visited[neighbor]){
            dfs(neighbor, src, timer, disc, low, ans, adj, visited);
            low[src] = min(low[src], low[neighbor]);
            //check if bridge
            if(low[neighbor] > disc[src]){
                ans.push_back({src, neighbor});
            }
        }
        else{
            //back edge
            low[src] = min(low[src], disc[neighbor]);
        }
    }  
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    //create adjacency list
    unordered_map<int, list<int>> adj;

    for(int i = 0; i < edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0; // to track the time at which node comes in dfs call

    vector<int> disc(v, -1); // represents the discovery time of node
    vector<int> low(v, -1);// represents the earliest possible discovery time for each node
    int parent = -1; // represents the parent node
    unordered_map<int, bool> visited; // keeps track of visited nodes

    vector<vector<int>> ans;

    //perform the dfs
    for(int i = 0; i < v; i++){
        if(!visited[i]){
            dfs(i, parent, timer, disc, low, ans, adj, visited);
        }
    }

    return ans;
}
int main(){
    
    return 0;
}




