#include<bits/stdc++.h>
using namespace std;

/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=AsAdKHkITBQ
    Company Tags                : Google, Facebook, Apple, Amazon, Netflix, Flipkart
    GfG Link                    : https://practice.geeksforgeeks.org/problems/disjoint-set-union-find/1
*/


int find(int parent[], int x){
    if(parent[x] == x){
        return x;
    }

    return parent[x] = find(parent, parent[x]); //Path Compression
}

void unionSet(int parent[], int x, int y){
    int x_parent = find(parent, x);
    int y_parent = find(parent, y);

    if(x_parent == y_parent){
        return;
    }

    parent[x] = y;
}


int main(){
    
    return 0;
}