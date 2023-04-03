//Approach 1 - Using Disjoint Set


#include <bits/stdc++.h>
using namespace std;

//function to sort on the bases of weights 
bool cmp(vector<int> &a, vector<int> &b){
    return a[2] < b[2];
}

//function to initialize the rank and parent
void makeSet(vector<int> &parent, vector<int> &rank, int n){
    for(int i = 0; i < n; i++){
        parent[i] = i; //intially all nodes are parent of themselves
        rank[i] = 0;
    }
}

//function to find parent
int findParent(vector<int> &parent, int node){
    //base case
    if(parent[node] == node){
        return node;
    }

    //path compression logic
    return parent[node] = findParent(parent, parent[node]);
}

//fuction to perform set union operation
void unionSet(int u, int v, vector<int> &parent, vector<int> &rank){
    u = findParent(parent, u);
    v = findParent(parent, v);

    if(rank[u] < rank[v]){
        parent[u] = v;
    }
    else if(rank[u] > rank[v]){
        parent[v] = u;
    }
    else{
        parent[v] = u;
        rank[u]++;
    }
}

int minimumSpanningTree(vector<vector<int>> &edges, int n)
{
    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent, rank, n);

    int totalCost = 0;

    //step - 1 sort the edges
    sort(edges.begin(), edges.end(), cmp);

    for(int i = 0; i < edges.size(); i++){
        int u = findParent(parent, edges[i][0]);
        int v = findParent(parent, edges[i][1]);
        int wt = edges[i][2];


        if(u != v){
            totalCost += wt;
            unionSet(u, v, parent, rank);
        }
    }

    return totalCost;
}

int main(){

    return 0;
}