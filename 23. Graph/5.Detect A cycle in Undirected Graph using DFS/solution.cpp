// Solution link: https://takeuforward.org/data-structure/cycle-detection-in-undirected-graph-using-dfs/
// CodeStudio link: https://bit.ly/3npFdrn
// Leetcode link: https://leetcode.com/problems/course-schedule/
// Solution link: https://takeuforward.org/data-structure/detect-a-cycle-in-undirected-graph-breadth-first-search/
// CodeStudio link: https://bit.ly/3npFdrn
// Leetcode link: https://leetcode.com/problems/course-schedule/
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
string cycleDetection (vector<vector<int>>& edges, int V, int m)
{
    vector<int> graph[V+1];
    buildGraph(graph, edges);
    vector<bool> visited(V+1, false);
    queue<pair<int,int>> Q;
    for(int i=1; i<=V; i++)

   {
     if(!visited[i])
        Q.push({i,-1}),visited[i] = 1;
    while(!Q.empty()) {
        pair<int,int> pi = Q.front();
        Q.pop();
        int v = pi.first;
        int parent = pi.second;
        for(int x: graph[v]) {
            if(!visited[x])
                Q.push({x,v}),visited[x] = 1;
            else if(x != parent)
                return "Yes";
        }
    }}
    return "No";
}
