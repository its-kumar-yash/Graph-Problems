#include<bits/stdc++.h>
using namespace std;



void topologicalsort(int node,unordered_map<int,list<int>>&adj,unordered_map<int,bool>&visited,stack<int>&st){
	visited[node]=true;
	for(auto nbr:adj[node]){
		if(!visited[nbr])
			topologicalsort(nbr,adj,visited,st);
	}
	st.push(node);	
}

void dfs(int node,unordered_map<int,list<int>>&trans,unordered_map<int,bool>&visited2){
	visited2[node]=true;
	for(auto nbr:trans[node]){
		if(!visited2[nbr])
			dfs(nbr,trans,visited2);
	}
}


int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	// create adjacency and transpose
	unordered_map<int,list<int>>adj,trans;
	for(int i=0;i<edges.size();i++){
		int u=edges[i][0];
		int v=edges[i][1];
		adj[u].push_back(v);
		trans[v].push_back(u);
	}
	//getting topological sorting
	stack<int>st;
	unordered_map<int,bool>visited(v);
	unordered_map<int,bool>visited2(v);

	for(int i=0;i<v;i++){
		if(!visited[i]){
			topologicalsort(i,adj,visited,st);
		}
	}
	int componenetCount=0;
	//calling dfs in topological order
	while(!st.empty()){
		int top=st.top();
		st.pop();
		//whenever a call for a strongly connected components complete it comes back
		if(!visited2[top]){
			//here we record the no of times it comes back
			componenetCount++;
			dfs(top,trans,visited2);
		}
	}
	return componenetCount;

}
int main(){
    
    return 0;
}


// Striver 
// Expected Time Complexity: O(V+E).
// Expected Auxiliary Space: O(V+E).
// } Driver Code Ends
class Solution
{
	public:
	   
	void dfs(int src, vector<vector<int>> &adj, stack<int> &st, vector<bool> &visited){
	   visited[src] = true;
	   
	   for(auto &v : adj[src]){
	       if(!visited[v]){
	           dfs(v, adj, st, visited);
	       }
	   }
	   
	   st.push(src);
	}
	
	void dfs3(int src, vector<bool> &visited, vector<int> adjT[]){
	   visited[src] = true;
	   
	   for(auto &v : adjT[src]){
	       if(!visited[v]){
	           dfs3(v, visited, adjT);
	       }
	   }

	}
	
	
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {   
        // step 1 - sort the nodes according to finishing time
        vector<bool> visited(V, false);
        stack<int> st; // to store the order
        
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                dfs(i, adj, st, visited);
            }
        }
        
        //step 2 - transpose the graph
        vector<int> adjT[V];
        for(int u = 0; u < V; u++){
            visited[u] = false;
            for(auto &v : adj[u]){
                adjT[v].push_back(u);
            }
        }
        
        //step 3 - perform dfs on topo sort order
        int scc = 0;
        
        while(!st.empty()){
            int top = st.top();
            st.pop();
            
            if(!visited[top]){
                scc++;
                dfs3(top, visited, adjT);
            }
        }
        
        
        return scc;
        
        
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends