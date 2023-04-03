#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int vertex, int edge, int start, int end, vector<vector<int>> edges){
    //create adjacency list
    unordered_map<int, list<int>> adj;
    for(int i = 0; i < edge; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //bfs karo
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;

    queue<int> q;

    //push src node into queue, mark it visited and mark its parent as -1
    q.push(start);
    visited[start] = true;
    parent[start] = -1;

    //to populate the parent list
    while(!q.empty()){
        int front = q.front();
        q.pop();

        //traverse for neighbours of front node
        for(auto neighbour : adj[front]){
            if(!visited[neighbour]){
                visited[neighbour] = true;
                parent[neighbour] = front;
                q.push(neighbour);
            }
        }
    }

    //finding shortest path using parent node
    vector<int> ans;
    int currNode = end;
    ans.push_back(currNode);

    while(currNode != start){
        currNode = parent[currNode];
        ans.push_back(currNode);
    }

    //reverse the ans before returning
    reverse(ans.begin(), ans.end());

    return ans;
}

int main(){
    // v - no. of vertices
    // e - no. of edges
    int V, E;
    cin>> V>> E;

    int st, end;
    cin>> st>> end;

    vector<vector<int>> edges;

    for(int i = 0; i < E; i++){
        int u, v;
        cin>>u>>v;

        edges.push_back({u, v});
    }

    vector<int> ans = shortestPath(V, E, st, end, edges);

    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}



//Shortest path in Undirected Graph having unit distance

// You are given an Undirected Graph having unit weight, Find the shortest path from src to all the vertex and if it is unreachable to reach any vertex, then return -1 for that vertex.


// Input:
// n = 9, m= 10
// edges=[[0,1],[0,3],[3,4],[4 ,5]
// ,[5, 6],[1,2],[2,6],[6,7],[7,8],[6,8]] 
// src=0
// Output:
// 0 1 2 1 2 3 3 4 4
// Second Approach

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int> adj[N];
        for(int i = 0; i < M; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        queue<int> q;
        
        vector<int> dict(N, INT_MAX);

        
        q.push(src);
        dict[src] = 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto i : adj[node]){
                if(dict[node] + 1 < dict[i]){
                    dict[i] = dict[node] + 1;
                    q.push(i);
                }
            }
        }
        
        
        for(auto & x : dict){
            if(x == INT_MAX){
                x = -1;
            }
        }
        
        return dict;
        
    }
};


