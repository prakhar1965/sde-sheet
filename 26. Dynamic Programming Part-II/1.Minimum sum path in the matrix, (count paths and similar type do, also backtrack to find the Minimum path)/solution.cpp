// Solution link: https://takeuforward.org/data-structure/minimum-path-sum-in-a-grid-dp-10/
// CodeStudio link: https://bit.ly/3zWJEin
// Leetcode link: https://leetcode.com/problems/minimum-path-sum/
#include<bits/stdc++.h>
using namespace std;
int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(i == 0 && j != 0)
                grid[i][j] += grid[i][j-1];
            else if(i != 0 && j == 0) 
                grid[i][j] += grid[i-1][j];
            else if(i != 0 && j != 0)
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
        }
    }
    return grid[n-1][m-1];
}