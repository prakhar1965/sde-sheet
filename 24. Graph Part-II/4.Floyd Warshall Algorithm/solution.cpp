// CodeStudio link: https://bit.ly/3Kb41Ny
// Leetcode link: https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1
int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {

    vector<vector<int>> weights(n+1, vector<int>(n+1, 1e9));
    for(int i=1; i<=n; i++) weights[i][i] = 0;

    for(auto it: edges) {
        weights[it[0]][it[1]] = it[2];
    }

    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(weights[i][k] != 1e9 && weights[k][j] != 1e9 && weights[i][j] > weights[i][k] + weights[k][j]) {
                    weights[i][j] = weights[i][k] + weights[k][j];
                }
            }
        }
    }
    return weights[src][dst];
}