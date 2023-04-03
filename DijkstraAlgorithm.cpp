
//Approach 1 - Using Set

#include<bits/stdc++.h>
using namespace std;

int INF = INT_MAX;

vector<int> dijkstra(int vertex, int edge, int source, vector<vector<int>> & edges){
    //create adjacency list of weighted graph
    unordered_map<int, list<pair<int, int>>> adj;

    for(int i = 0; i < edge; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];

        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }

    //create distance vector
    vector<int> dist(vertex, INF);

    //create set {dist, node}
    //to get minimum edge every time
    set<pair<int, int>> st;

    //initialize source node with distance 0
    dist[source] = 0;

    //also insert it into set
    st.insert({0, source});

    while(!st.empty()){
        //fetch top record
        auto top = *(st.begin());

        int nodeDistance = top.first;
        int topNode = top.second;

        //remove the top record
        st.erase(st.begin());

        //traverse on the neighbour
        for(auto neighbor : adj[topNode]){
            if(nodeDistance + neighbor.second < dist[neighbor.first]){
                auto record = st.find({dist[neighbor.first], neighbor.first});

                //if record already exist in set
                //remove the existing record
                if(record != st.end()){
                    st.erase(record);
                }

                //distance update
                dist[neighbor.first] = nodeDistance + neighbor.second;

                //record push in set
                st.insert({dist[neighbor.first], neighbor.first});
            } 
        }
    }
    return dist;
}


int main(){
    // v - no. of vertices
    // e - no. of edges
    int V, E;
    cin>> V>> E;

    vector<vector<int>> edges;

    for(int i = 0; i < E; i++){
        int u, v, wt;
        cin>>u>>v>>wt;

        edges.push_back({u, v});
        edges[u].push_back(wt);
    }

    vector<int> ans = dijkstra(V, E, 0, edges);

    for(auto i : ans){
        if(i == INF){
            cout<<"INF"<<" ";
        }
        else{
            cout<<i<<" ";
        }
    }

    return 0;
}


//Appraoch 2  - Using Priority Queue


// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        vector<int> dist(V, INT_MAX);
        dist[S] = 0;
        pq.push({0, S});
        
        
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            
            int node = top.second;
            int nodeDist = top.first;
            
            //exploring neigghbour
            for(auto neighbour : adj[node]){
                if(nodeDist + neighbour[1] < dist[neighbour[0]]){
                    pq.push({nodeDist + neighbour[1],  neighbour[0]});
                    dist[neighbour[0]] = nodeDist + neighbour[1];
                } 
            }
        }
        
        return dist;
    }
};

