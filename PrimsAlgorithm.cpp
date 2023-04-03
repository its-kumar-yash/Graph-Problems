
//Approach 1 - Using Vectors
// TC - O(N^2)

#include <bits/stdc++.h>
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // create adj list
    unordered_map<int, list<pair<int, int>>> adj;

    for (int i = 0; i < g.size(); i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int wt = g[i].second;

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    // create three data structures

    // for 1 based indexing

    // Key values used to pick minimum weight edge in cut
    vector<int> key(n + 1); // to track the minimum distance between
    // Array to store constructed MST
    vector<int> parent(n + 1); // to track the parent node
    // To represent set of vertices included in MST
    vector<bool> mst(n + 1); // to track whether node included in mst or not

    // initialization of these data structures
    for (int i = 0; i <= n; i++)
    {
        key[i] = INT_MAX;
        parent[i] = -1;
        mst[i] = false;
    }

    // algo starts

    // Always include first 1st vertex in MST.
    // Make key 0 so that this vertex is picked as first
    // vertex.

    key[1] = 0; // source node
    // First node is always root of MST
    parent[1] = -1; // no parent for source node

    // The MST will have V vertices
    // traversing over all nodes
    for (int i = 1; i < n; i++)
    {

        // Pick the minimum key vertex from the
        // set of vertices not yet included in MST
        // step 1 - find mini node
        int mini = INT_MAX;
        int u;

        for (int v = 1; v <= n; v++)
        {
            if (mst[v] == false && key[v] < mini)
            {
                mini = key[v];
                u = v;
            }
        }

        // step 2 - mark mini node as visited
        //  Add the picked vertex to the MST Set
        mst[u] = true;

        // Update key value and parent index of
        // the adjacent vertices of the picked vertex.
        // Consider only those vertices which are not
        // yet included in MST
        // step 3 - check its adj nodes
        for (auto it : adj[u])
        {

            // graph[u][v] is non zero only for adjacent
            // vertices of m mstSet[v] is false for vertices
            // not yet included in MST Update the key only
            // if graph[u][v] is smaller than key[v]
            int v = it.first;
            int w = it.second;
            if (mst[v] == false && w < key[v])
            {
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    vector<pair<pair<int, int>, int>> result;

    for (int i = 2; i <= n; i++)
    {
        result.push_back({{parent[i], i}, key[i]});
    }

    return result;
}



//Approach 2 - Using Heap
// TC - O(ElogV)


vector<pair<pair<int, int>, int>> calculatePrimsMST2(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    //create adj list
    unordered_map<int, list<pair<int, int>>> adj;

    for(int i = 0; i < g.size(); i++){
        int u = g[i].first.first;
        int v = g[i].first.second;
        int wt = g[i].second;

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }


    //create three data structures

    //for 1 based indexing
    vector<int> key(n + 1); //to track the minimum distance between
    vector<int> parent(n + 1); //to track the parent node
    vector<bool> mst(n + 1); // to track whether node included in mst or not

    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;


    for(int i = 0; i <= n; i++){
        key[i] = INT_MAX;
        parent[i] = -1;
        mst[i] = false;
    }


    //algo starts
    key[1] = 0; // source node
    parent[1] = -1; //no parent for source node

    // Insert source itself in priority queue and initialize
    // its key as 0.
    pq.push({key[1], 1});


    //traversing over all nodes
    while(!pq.empty()){


        auto top = pq.top();
        pq.pop();

        int u = top.second;
        int mini = top.first;

        //step 2 - mark mini node as visited
        mst[u] = true;


        //step 3 - check its adj nodes
        for(auto it : adj[u]){
            int v = it.first;
            int w = it.second;
            if(mst[v] == false && w < key[v]){
                parent[v] = u;
                key[v] = w;
                pq.push({key[v], v});
            }
        }
    }

    vector<pair<pair<int, int>, int>> result;

    for(int i = 2; i <= n; i++){
        result.push_back({{parent[i], i}, key[i]});
    }   

    return result;

}


int main()
{

    return 0;
}
