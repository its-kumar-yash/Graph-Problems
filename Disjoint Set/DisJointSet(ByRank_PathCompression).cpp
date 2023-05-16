#include<bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<int> rankn;

int find(int x){
    if(x == parent[x]){
        return x;
    }

    return parent[x] = find(parent[x]); //Path Compression
}

void Union(int x, int y){
    int x_parent = find(x);
    int y_parent = find(y);

    if(x_parent == y_parent){
        return;
    }
    if(x_parent > y_parent){
        parent[y_parent] = x_parent;
    }
    else if(x_parent < y_parent){
        parent[x_parent] = y_parent;
    }
    else{
        parent[x_parent] = y_parent;
        rankn[y_parent]++;
    }
}

int main(){
    
    return 0;
}