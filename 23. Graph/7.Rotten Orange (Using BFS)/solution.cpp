// Solution link: https://takeuforward.org/data-structure/rotten-oranges-min-time-to-rot-all-oranges-bfs/
// CodeStudio link: https://bit.ly/33zH0TC
// Leetcode link: https://leetcode.com/problems/rotting-oranges/
#include<bits/stdc++.h>
using namespace std;
int X[] = {-1, 1, 0, 0};
int Y[] = {0, 0, 1, -1};
bool check(int x, int y, int n, int m) 
{
    if(x<0 || x>=n || y<0 || y>=m) return false;
    return true;
}
int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    queue<pair<int,int>> Q;
    int totOranges = 0,cnt = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(grid[i][j] != 0) totOranges++;
            if(grid[i][j] == 2) Q.push({i,j});
        }
    }
    int time = 0;
    while(!Q.empty()) {
        int size = Q.size();
        cnt += size;
        for(int i=0; i<size; i++) {
            pair<int,int> curr = Q.front();
            Q.pop();
            int x = curr.first, y = curr.second;
            for(int j=0; j<4; j++) {
                int newX = x + X[j];
                int newY = y + Y[j];
                if(check(newX, newY, n, m)) {
                    if(grid[newX][newY] == 1)
                        Q.push({newX, newY}),grid[newX][newY] = 2;
                }
            }
        }
        if(!Q.empty()) time++;
 
    }
    return (cnt == totOranges)? time : -1;
}
