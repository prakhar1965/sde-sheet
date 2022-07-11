// Solution link: https://takeuforward.org/data-structure/bellman-ford-algorithm-shortest-distance-with-negative-edge/
// CodeStudio link: https://bit.ly/3GwAf3A
// Leetcode link: https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/0/?fbclid=IwAR2_lL0T84DnciLyzMTQuVTMBOi82nTWNLuXjUgahnrtBgkphKiYk6xcyJU

int bellmonFord(int V, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<int>dis(V+1, 1e9);
    dis[src] = 0;
    for(int i=0; i<V; i++) {
        for(auto it: edges) {
            if(dis[it[0]] + it[2] < dis[it[1]] && dis[it[0]] != 1e9) {
                dis[it[1]] = it[2] + dis[it[0]];
            }
        }
    }
    return dis[dest];
}