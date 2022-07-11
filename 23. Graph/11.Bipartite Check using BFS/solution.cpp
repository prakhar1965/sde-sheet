// CodeStudio link: https://bit.ly/3tps98W
// Leetcode link: https://leetcode.com/problems/is-graph-bipartite/
#include<bits/stdc++.h>
using namespace std;
void buildGraph(vector<int> *graph, vector<vector<int>> &edges)
{
    int E = edges.size();
    for(int i=0; i<E; i++) {
        for(int j=0; j<E; j++) {
            if(edges[i][j]) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
}
bool dfs(int v,int parentColor, vector<int> *graph, vector<bool> &visited, vector<int> &colour) 
{
    visited[v] = true;
    colour[v] = parentColor^1;
    for(int u: graph[v]) {
        if(colour[u] == colour[v])
            return 0;
        if(!visited[u])
            if(dfs(u, colour[v], graph, visited, colour) == 0)
                return 0;
    }
    return 1;
}
bool isGraphBirpatite(vector<vector<int>> &edges) {
    vector<int> graph[edges.size()];
    buildGraph(graph, edges);
    vector<bool> visited(edges.size(), false);
    vector<int> colour(edges.size(), -1);
    
    for(int i=0; i<edges.size(); i++) {
        if(!visited[i]) {
            if(dfs(0,0,graph,visited, colour) == 0)
                return 0;
        }
    }
    return 1;
}