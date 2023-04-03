//Moonfrog Labs Flipkart Morgan Stanley Accolite Amazon Microsoft OYO Rooms Samsung D-E-Shaw Visa

// Expected Time Complexity: O(V + E).
// Expected Auxiliary Space: O(V).

#include<bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(int vertex, int edge, vector<vector<int>> edges){
    //step 1 - create adjacency list
    unordered_map<int, list<int>> adj;

    for(int i = 0; i < edge; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    //step 2 - creating indegree DS and find all indegree
    vector<int> indegree(vertex);
    for(auto i : adj){
        for(auto j: i.second){
            indegree[j]++;
        }
    }
    

    //step 3 - performing bfs traversal

    //0 indegree walo ko push krdo
    queue<int> q;
    
    for(int i = 0; i < vertex; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    //do bfs
    vector<int> ans;

    while(!q.empty()){
        int front = q.front();
        q.pop();

        //ans store
        ans.push_back(front);

        //update indegree of neighbours
        for(auto neighbor : adj[front]){
            indegree[neighbor]--;
            //and if indegree becomes zero push into queue
            if(indegree[neighbor] == 0){
                q.push(neighbor);
            }
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

    vector<int> ans = topologicalSort(V, E, edges);

    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}

//Approach 2

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    //creating indegree data structure
	    vector<int> inDegree(V);
	    
	    for(int i = 0; i < V; i++){
	        for(auto j : adj[i]){
	            inDegree[j]++;
	        }
	    }
	    
	    vector<int> ans;
	    
	    queue<int> q;
	    
	    for(int i = 0; i < V; i++){
	        if(inDegree[i] == 0){
	            q.push(i);
	        }
	    }
	    
	    while(!q.empty()){
	        int front = q.front();
	        q.pop();
	        
	        
	        ans.push_back(front);
	        
	        for(auto neighbour : adj[front]){
	            inDegree[neighbour]--;
	            if(inDegree[neighbour] == 0){
	                q.push(neighbour);
	            }
	        }
	    }
	    
	    
	    return ans;
	}
};

