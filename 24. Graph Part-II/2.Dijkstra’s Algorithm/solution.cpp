// Solution link: https://takeuforward.org/data-structure/dijkstras-algorithm-shortest-distance/
// CodeStudio link: https://bit.ly/3qrEHLm
// Leetcode link: https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
#include<bits/stdc++.h>
using namespace std;
void buildGraph(vector<pair<int,int>> *graph, vector<vector<int>> &edges)
{
    int E = edges.size();
    for(int i=0; i<E; i++) {

        graph[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        graph[edges[i][1]].push_back({edges[i][0], edges[i][2]});
       
    }
}
vector<int> dijkstra(vector<vector<int>> &vec, int V, int edges, int source) {
    vector<pair<int,int>> graph[V];
    buildGraph(graph, vec);
    vector<int>dis(V, INT_MAX);
    dis[source] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, source});
    while(!pq.empty()) {
        pair<int,int> curr = pq.top();
        pq.pop();
        int v = curr.second, dist = curr.first;

        for(auto it: graph[v]) {
            int next = it.first;
            int nexDis = it.second;
            if(nexDis + dis[v] < dis[next]) {
                dis[next] = nexDis + dis[v];
                pq.push({dis[next], next});
            }
        }
    }
    return dis;
}
