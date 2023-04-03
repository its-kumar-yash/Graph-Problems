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