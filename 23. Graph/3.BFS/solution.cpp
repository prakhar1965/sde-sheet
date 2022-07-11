// Solution link: https://takeuforward.org/data-structure/breadth-first-searchbfs-level-order-traversal/
// CodeStudio link: https://bit.ly/3rgb26U
// Leetcode link: https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
#include<bits/stdc++.h>
using namespace std;
void buildGraph(vector<int> *graph, vector<pair<int, int>> &edges)
{
    int E = edges.size();
    for(int i=0; i<E; i++) {
        int x = edges[i].first;
        int y = edges[i].second;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
}
vector<int> BFS(int V, vector<pair<int, int>> edges)
{
    vector<int> graph[V];
    buildGraph(graph, edges);
    for(int i=0; i<V; i++) {
        sort(graph[i].begin(), graph[i].end());
    }
    vector<bool> visited(V, false);
    queue<int> Q;
    vector<int> ans;
    for(int i=0; i<V; i++)
    {
    if(!visited[i])
        Q.push(i),visited[i] = 1;
    while(!Q.empty()) {
        int v = Q.front();
        Q.pop();
        ans.push_back(v);
        for(int x: graph[v]) {
            if(!visited[x])
                Q.push(x),visited[x] = 1;
        }
    }
    }

    return ans;
}