#include<bits/stdc++.h>
using namespace std;

template <typename T> // to create a genric graph

//craeting implementation for graph
class graph{
public:
    //initializes map
    //to represent graph as adjacency list
    unordered_map<T , list<T>> adj;

    //function to add an edge between two nodes
    void addEdge(T u, T v, bool direction) {
        //direction -> 0 -> undirected
        //direction -> 1 -> directed

        //create an edge between u and v
        adj[u].push_back(v);

        if(direction == 0){
            adj[v].push_back(u);
        }
    }

    void printAdj(){
        for(auto i : adj){
            cout << i.first << "-> ";
            for(auto j : i.second){
                cout << j << " ";
            }
            cout<< endl;
        }
    }

};



int main(){
    
    int n;
    cout<<"Enter the number of nodes"<<endl;
    cin >> n;

    int m;
    cout<<"Enter the number of edges"<<endl;
    cin >> m;


    graph<int> g; //creating a int type graph

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        //creating an undirected graph
        g.addEdge(u,v, 0);
    }


    //printing the graph
    g.printAdj();


    return 0;
}