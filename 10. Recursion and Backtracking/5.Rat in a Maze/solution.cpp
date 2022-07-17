// Solution link: https://takeuforward.org/data-structure/rat-in-a-maze/
// CodeStudio link: https://bit.ly/3fmwP7t
// Leetcode link: https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
#include<bits/stdc++.h>
using namespace std;
int dirX[4] = {-1,1,0,0};
int dirY[4] = {0,0,1,-1};
bool isSafe(int x, int y, int n) {
    if(x >=0 && x<n && y>=0 && y<n) return true;
    return false;
}
void solve(int x, int y, vector<vector<int>>& ans, vector<vector<int>> &path, vector<vector<int>> &maze, int n) {
    if(x == n-1 && y == n-1) {
        vector<int> pa;
        for(auto vec: path) {
            for(auto in: vec){
                pa.push_back(in);
            }
        }
        ans.push_back(pa);
        return;
    }
    for(int i=0; i<=3; i++) {
        int newX = x+dirX[i];
        int newY = y+dirY[i];
        if(isSafe(newX, newY, n) && maze[newX][newY] == 1 && path[newX][newY] != 1) {
            path[newX][newY] = 1;
            solve(newX,newY, ans, path,maze,n);
            path[newX][newY] = 0;
        }
    }

}
vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  
  vector<vector<int>> ans;
  vector<vector<int>>path(n, vector<int>(n, 0));
  path[0][0] = 1;
    if(maze[0][0])
          solve(0,0, ans,path,maze,n);
  return ans;
}