// Solution link: https://takeuforward.org/data-structure/detect-a-cycle-in-directed-graph-using-dfs/
// CodeStudio link: https://bit.ly/3FrzaZp
// Leetcode link: https://leetcode.com/problems/course-schedule/
void buildGraph(vector<int> *graph, vector<pair<int, int>> &edges)
{
    int E = edges.size();
    for(int i=0; i<E; i++) {
        int x = edges[i].first;
        int y = edges[i].second;
        graph[x].push_back(y);
    }
}
bool dfs(int v, vector<int> *graph, vector<bool> &visited,vector<bool> &dfsVisited) 
{
    visited[v] = 1;
    dfsVisited[v] = 1;
    for(int u: graph[v]) {
        if(!visited[u]){
            if(dfs(u, graph, visited, dfsVisited))
                return 1;
        }   
        else if(dfsVisited[u])
                return 1;
    }
    dfsVisited[v] = 0;
    return 0;
}
int detectCycleInDirectedGraph(int V, vector < pair < int, int >> & edges) {
    vector<int> graph[V+1];
    buildGraph(graph, edges);
    vector<bool> visited(V+1, false);
    vector<bool> dfsVisited(V+1, false);
    
    for(int i=0; i<V; i++) {
        if(!visited[i]) {
            if(dfs(i, graph, visited, dfsVisited))
                return 1;
        }
    }
    return 0;
}