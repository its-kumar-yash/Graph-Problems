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

//Striver Solution

// https://takeuforward.org/graph/bridges-in-graph-using-tarjans-algorithm-of-time-in-and-low-time-g-55/
// } Driver Code Ends
class Solution
{
	public:
	int timer = 0;
	
	void dfs(int node, int parent, vector<int> &vis, 
	vector<int> adj[], int tin[], int low[], int &ans, int &c, int &d){
	    vis[node] = 1;
	    tin[node] = low[node] = timer;
	    
	    timer++;
	    
	    for(auto child : adj[node]){
	        if(child == parent) continue;
	        
	        if(vis[child] == 0){
	            dfs(child, node, vis, adj, tin, low, ans, c, d);
	            low[node] = min(low[child], low[node]);
	            //node --- it
	            if(low[child] > tin[node] && ((child == c && node == d) || (child == d && node == c))){
	                ans = 1;
	            }
	        }
	        else{
	            low[node] = min(low[node], low[child]);
	        }
	    }
	}
	
	
	
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        vector<int> vis(V, 0);
        int tin[V];
        int low[V];
        vector<vector<int>> bridges;
        int ans = 0;
        for(int i = 0; i < V; i++){
            if(vis[i] == 0){
                dfs(i, -1, vis, adj, tin, low, ans, c, d);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}


// } Driver Code Ends


