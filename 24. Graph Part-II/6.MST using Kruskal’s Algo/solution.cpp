// Solution link: https://takeuforward.org/data-structure/minimum-spanning-tree-mst-using-kruskals-algo/'
// CodeStudio link: https://bit.ly/3I1VqL9
// Leetcode link: https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1
#include<bits/stdc++.h>
using namespace std;
int findParent(int x, vector<int> &parent) {
    if(parent[x] == -1) return x;
    return parent[x] = findParent(parent[x], parent);
}
void unionUtil(int u, int v, vector<int> &parent) {
    parent[findParent(u, parent)] = findParent(v, parent);
}
int kruskalMST(int n, int m, vector<vector<int>> &edges) {
    
    sort(edges.begin(), edges.end(), [](vector<int>a, vector<int>b) {
        return a[2] < b[2];
    });
    int minWt = 0;
    int E = edges.size();
    vector<int> parent(n+1, -1);
    for(int i=0; i<E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        if(findParent(u, parent) != findParent(v, parent)) {
            minWt += wt;
            unionUtil(u,v, parent);
        }
    }
    return minWt;
}