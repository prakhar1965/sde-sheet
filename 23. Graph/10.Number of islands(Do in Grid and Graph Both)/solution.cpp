// CodeStudio link: https://bit.ly/3KaSCND
// Leetcode link: https://leetcode.com/problems/number-of-islands/
#include<bits/stdc++.h>
using namespace std;
int X[] = {0, 0, 1, 1,-1,-1, 1,-1};
int Y[] = {1,-1, 0,-1, 1, 0, 1,-1};
bool check(int x, int y, int n, int m) {
    if(x<0 || x>=n || y<0 || y>=m) 
        return 0;
    return 1;
}
void dfs(int i,int j,vector<vector<bool>> &vis, int **arr) {
    vis[i][j] = 1;
    int n = vis.size();
    int m = vis[0].size();
    for(int a=0; a<7; a++) {
        int newI = i+X[a];
        int newJ = j+Y[a];
        if(check(newI,newJ,n,m) && !vis[newI][newJ] && arr[newI][newJ])
            dfs(newI,newJ,vis,arr);
    }

}
int getTotalIslands(int** arr, int n, int m)
{
   vector<vector<bool>> vis(n, vector<int>(m, 0));
   int island = 0;
   for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
        if(!vis[i][j] && arr[i][j]) {
            island++;
            dfs(i,j,vis,arr);
        }
    }
   }
   return island;
}
