// Solution link: https://takeuforward.org/data-structure/depth-first-search-dfs-traversal-graph/
// CodeStudio link: https://bit.ly/33BcXeg
// Leetcode link: https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
#include<bits/stdc++.h>
using namespace std;
void buildGraph(vector<int> *graph, vector<vector<int>> &edges)
{
    int E = edges.size();
    for(int i=0; i<E; i++) {
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }
}
void dfs(int v, vector<int> *graph, vector<bool> &visited, vector<int> &ans) 
{
    visited[v] = true;
    ans.push_back(v);
    for(int u: graph[v]) {
        if(!visited[u])
            dfs(u, graph, visited, ans);
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<int> graph[V];
    buildGraph(graph, edges);
    vector<bool> visited(V, false);
    vector<vector<int>> ans;
    for(int i=0; i<V; i++) {
        if(!visited[i]) {
            vector<int> node;
            dfs(i,graph, visited, node);
            sort(node.begin(), node.end());
            ans.push_back(node);
        }
    }
    return ans;
}