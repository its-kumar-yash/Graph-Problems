//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<int> parent;
    vector<int> rank;
    
    int find(int x){
        if(parent[x] == x){
            return x;
        }
        
        return parent[x] = find(parent[x]);
    }
    
    void Union(int x, int y){
        int parent_x = find(x);
        int parent_y = find(y);
        
        if(parent_x == parent_y){
            return;
        } 
        
        if(rank[parent_x] > rank[parent_y]){
            parent[parent_y] = parent_x;
        }
        else if(rank[parent_x] < rank[parent_y]){
            parent[parent_x] = parent_y;
        }
        else{
            parent[parent_x] = parent_y;
            rank[parent_y]++;
        }
        
    }
	int detectCycle(int V, vector<int>adj[])
	{
	    parent.resize(V);
	    rank.resize(V, 0);
	    //initialing parent vector
	    for(int i = 0; i < V; i++){
	        parent[i] = i;
	    }
	    
	    //Cycle Detection
	    for(int u = 0; u < V; u++){
	        for(auto &v : adj[u]){
	            if(u < v){
	                int parent_u = find(u);
	                int parent_v = find(v);
	                
	                if(parent_u == parent_v){
	                    return 1;
	                }
	                
	                Union(u, v);
	            }
	        }
	    }
	    
	    return false;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.detectCycle(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends