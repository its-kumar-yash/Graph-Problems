//implementating breadth-first search

// You are given an undirected and disconnected graph G(V, E) having V vertices numbered from 0 to V-1 and E edges. Your task is to print its BFS traversal starting from the 0th vertex.
// BFS or Breadth-First Traversal of a graph is an algorithm used to visit all of the nodes of a given graph.
// In this traversal algorithm, one node is selected, and then all of the adjacent nodes are visited one by one.
// An undirected graph is a graph where all the edges are bidirectional, i.e., they point from source to destination and destination to source.

#include<bits/stdc++.h>
using namespace std;

//function to create adjacency list
void createAdjList(unordered_map<int, set<int>> &adjList, vector<pair<int,int>> &edges){
    for(int i = 0; i < edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].insert(v);
        adjList[v].insert(u); // because graph is undirected
    }
}

//fucntion to perform bfs from given vertex
void bfs(unordered_map<int, set<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int vertex){
    //create a queue
    queue<int> q;
    //push the source vertex and mark it as visited
    q.push(vertex);
    visited[vertex] = true;

    while(!q.empty()){
        //pop front of queue
        int front = q.front();
        q.pop();

        //store it into ans
        ans.push_back(front);
        //add it to visited
        visited[front] = true;

        //push all neighbours to queueand mark it as visited
        for(auto node : adjList[front]){
            if(!visited[node]){
                q.push(node);
                visited[node] = true;
            }
        }
    }

}


vector<int> BFS(int vertex, vector<pair<int,int>> &edges){
    //step 1 - create adjacency list
    unordered_map<int, set<int>> adjList;
    
    createAdjList(adjList, edges);

    vector<int> ans;

    //step 2 - create visited list
    unordered_map<int, bool> visited;

    //step 3 - traverse all components of graph
    for(int i = 0; i < vertex; i++){
        //if the node is not visited then perform bfs
        if(!visited[i]){
            bfs(adjList, visited, ans, i);
        }
    }

    return ans;
}


int main(){
    
    // V - number of vertices
    // E - number of edges
    int V, E;
    cin >> V >> E ;
    
    vector<pair<int, int>> edges;


    for(int i = 0; i < E; i++){
        int u, v;
        //inputing edges between u and v
        pair<int, int> p;
        cin>>p.first >> p.second;

        edges.push_back(p);
    }


    vector<int> output = BFS(V, edges);

    for(auto i : output){
        cout<<i<<" ";
    }

    return 0;
}