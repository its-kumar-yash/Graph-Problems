//MicroSoft  Flipkart

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    //Using DFS Traversal
    bool dfs(int curr, vector<int>adj[], vector<int> &color, int &currColor){
        //assign color to curr node
        color[curr] = currColor;
        
        //check for the adjacent nodes
        
        for(auto &v : adj[curr]){
            //if dest node is of same color as curr node
            if(color[v] == color[curr]){
                return false;
            }
            
            //if node is not colored
            if(color[v] == -1){
                //find color
                int colorV = 1 - currColor;
                //move to next node
                if(dfs(v, adj, color, colorV) == false){
                    return false;
                }
            }
        }
        
        return true;
    }
    
	bool isBipartite(int V, vector<int>adj[]){
	    //this also works as visited array
	    //initially all nodes are -1
	    vector<int> color(V, -1);
	    
	    //start coloring nodes with any color
	    int currColor = 0;
	    
        //1 - RED
        //0 - GREEN
	    
	    for(int i = 0; i < V; i++){
	        if(color[i] == -1){
	            bool ans = dfs(i, adj, color, currColor);
	            
	            if(!ans){
	                return false;
	            }
	        }
	    }
	    
	    return true;
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
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}


//Using BFS

// } Driver Code Ends
class Solution {
public:
    bool bfs(int curr, vector<int>adj[], vector<int> &color, int &currColor){
        queue<int> q;
        
        q.push(curr);
        color[curr] = currColor;
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            
            for(auto &v : adj[front]){
                if(color[front] == color[v]){
                    return false;
                }
                
                else if(color[v] == -1){
                    //opposite color
                    color[v] = 1 - color[front];
                    q.push(v);
                }
            }
        }
        
        return true;
    }
    
	bool isBipartite(int V, vector<int>adj[]){
	    //this also works as visited array
	    //initially all nodes are -1
	    vector<int> color(V, -1);
	    
	    //start coloring nodes with any color
	    int currColor = 0;
	    
	    
	    for(int i = 0; i < V; i++){
	        if(color[i] == -1){
	            bool ans = bfs(i, adj, color, currColor);
	            
	            if(!ans){
	                return false;
	            }
	        }
	    }
	    
	    return true;
	}

};

// } Driver Code Ends