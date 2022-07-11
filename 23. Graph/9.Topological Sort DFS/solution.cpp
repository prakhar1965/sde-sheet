// Solution link: https://takeuforward.org/data-structure/topological-sort-bfs/
// CodeStudio link: https://bit.ly/33bapUo
// Leetcode link: https://practice.geeksforgeeks.org/problems/topological-sort/1
#include<bits/stdc++.h>
using namespace std;
void buildGraph(vector<int> *graph, vector<vector<int>> &edges, vector<int> &in)
{
    int E = edges.size();
    for(int i=0; i<E; i++) {
        graph[edges[i][0]].push_back(edges[i][1]);
        in[edges[i][1]]++;
    }
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {

    vector<int> graph[v];
    vector<int> in(v, 0);

    buildGraph(graph, edges, in);
    queue<int> Q;
    vector<int> ans;
    for(int i=0; i<v; i++) {
        if(in[i] == 0)
            Q.push(i);
    }
    while(!Q.empty()) {
        int v = Q.front();
        Q.pop();
        ans.push_back(v);
        for(int x: graph[v]) {
            in[x]--;
            if(in[x] == 0) Q.push(x);
        }
    }
    
    return ans;
}
