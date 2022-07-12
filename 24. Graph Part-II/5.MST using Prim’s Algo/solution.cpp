// Solution link: https://takeuforward.org/data-structure/minimum-spanning-tree-mst-using-prims-algo/
// CodeStudio link: https://bit.ly/3I5Ktbi
// Leetcode link: https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1
#include<bits/stdc++.h>
using namespace std;
void buildGraph(vector<pair<int,int>> *graph, vector<pair<pair<int, int>, int>> &edges)
{
    int E = edges.size();
    for(int i=0; i<E; i++) {
        graph[edges[i].first.first].push_back({edges[i].first.second, edges[i].second});
        graph[edges[i].first.second].push_back({edges[i].first.first, edges[i].second});
    }
}
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    vector<pair<int,int>> graph[n+1];
    buildGraph(graph, g);
    vector<bool> mst(n+1, 0);
    vector<int> minWeight(n+1, 1e9);
    minWeight[1] = 0;
    pair<int,int> edges[n+1];
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,1});

    while(!pq.empty()) {
        pair<int,int> curr = pq.top();
        pq.pop();
        int v = curr.second;
        mst[v] = 1; 
        for(auto it: graph[v]) {
            int weight = it.second;
            int u = it.first;
            if(mst[u] == 0 && weight < minWeight[u]) {
                minWeight[u] = weight;
                pq.push({weight, u});
                edges[u] = make_pair(v,weight); 
            }
        }
    }
    vector<pair<pair<int, int>, int>> ans;
    for(int i=2; i<=n; i++) {
        ans.push_back({{i,edges[i].first}, edges[i].second});
    }
    return ans;
}
