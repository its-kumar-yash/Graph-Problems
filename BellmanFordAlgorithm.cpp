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

int main()
{

    return 0;
}