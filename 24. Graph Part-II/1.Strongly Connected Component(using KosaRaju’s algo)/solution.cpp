// Solution link: https://takeuforward.org/data-structure/kosarajus-algorithm-for-strongly-connected-componentsscc/
// CodeStudio link: https://bit.ly/3twUKJP
// Leetcode link: https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/discuss/766485/kosaraju-algorithm-on
#include<bits/stdc++.h>
using namespace std;
void buildGraph(vector<int> *graph, vector<vector<int>> &edges)
{
    int E = edges.size();
    for(int i=0; i<E; i++) {
        graph[edges[i][0]].push_back(edges[i][1]);
    }
}
void buildTGraph(vector<int> *graph, vector<vector<int>> &edges)
{
    int E = edges.size();
    for(int i=0; i<E; i++) {
        graph[edges[i][1]].push_back(edges[i][0]);
    }
}
void dfs(int v, vector<int> *graph, vector<bool> &visited, stack<int> &s) 
{
    visited[v] = true;
    for(int u: graph[v]) {
        if(!visited[u])
            dfs(u, graph, visited, s);
    }
    s.push(v);
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
vector<vector<int>> stronglyConnectedComponents(int V, vector<vector<int>> &edges)
{
    vector<int> graph[V];
    buildGraph(graph, edges);
    vector<bool> visited(V, false);
    stack<int>s;
    for(int i=0; i<V; i++) {
        if(!visited[i])
            dfs(i, graph, visited,s);
    }
    vector<int> Tgraph[V];
    buildTGraph(Tgraph, edges);
    vector<bool>vis(V, false);
    vector<vector<int>> ans;
    while(!s.empty()) {
        int v = s.top();
        s.pop();
        if(!vis[v]) {
            vector<int> vec;
            dfs(v, Tgraph, vis, vec);
            ans.push_back(vec);
        }      
    }
    return ans;
}