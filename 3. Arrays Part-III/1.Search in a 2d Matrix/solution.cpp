// Solution link: https://takeuforward.org/data-structure/search-in-a-sorted-2d-matrix/
// CodeStudio link: https://bit.ly/3GD7NNa
// Leetcode link: https://leetcode.com/problems/search-a-2d-matrix/

#include <bits/stdc++.h> 
using namespace std;

bool findTargetInMatrix(vector<vector<int>>& mat, int m, int n, int target) {
    int row = 0;
    for(int i=0; i<m; i++) {
        if(mat[i][0] <= target) {
            if(i == m-1) 
                row = m-1;
            else{
                if(mat[i+1][0] > target) row = i;
            }
        }
    }

    for(int i=0; i<n; i++) {
        if(mat[row][i] == target)
            return true;
    }
    return false;
}