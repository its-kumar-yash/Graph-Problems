#include <bits/stdc++.h>
using namespace std;

int INF = 1e9;

int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges)
{
    vector<int> dist(n + 1, INF); // 1 based indexing
    dist[src] = 0;

    // n-1 times
    // for every node
    for (int i = 1; i <= n; i++)
    {
        // traverse all edges
        for (int j = 0; j < edges.size(); j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if (dist[u] != INF && (dist[u] + wt < dist[v]))
            {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // check for negative cycle
    int flag = 0;

    for (int j = 0; j < edges.size(); j++)
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];

        if (dist[u] != INF && (dist[u] + wt < dist[v]))
        {
            flag = 1;
        }
    }

    if(flag == 0){
        return dist[dest];
    }

    return -1;
}

//Striver 

//TC - O(V*E)

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> dist(V, 1e8);
        
        dist[S] = 0;
        
        //Relax for(V-1)time
        for(int i = 0; i < V - 1; i++){
            for(auto &vec : edges){
                int u = vec[0];
                int v = vec[1];
                int wt = vec[2];
                 //check if relax possible
                if(dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                }
            }
        }
        //checking cycle Nth relaxation
        bool flag = false;
        for(auto &vec : edges){
            int u = vec[0];
            int v = vec[1];
            int wt = vec[2];
                
            if(dist[u] + wt < dist[v]){
                flag = true;
                // dist[v] = dist[u] + wt;
            }
        }
        
        //negative cycle detect
        if(flag){
            return {-1};
        }
        //no negative cycle
        return dist;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, m;
        cin >> N >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends