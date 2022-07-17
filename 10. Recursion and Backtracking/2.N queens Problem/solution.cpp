// Solution link: https://takeuforward.org/data-structure/n-queen-problem-return-all-distinct-solutions-to-the-n-queens-puzzle/
// CodeStudio link: https://bit.ly/3zSZavC
// Leetcode link: https://leetcode.com/problems/n-queens/

#include<bits/stdc++.h>
using namespace std;

void solve(int col,vector<vector<int>>& board, vector<vector<int>> &ans, vector<int> &leftrow,
vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int n) {
       if (col == n) {
        vector<int>config;
        for(auto x: board) {
              for(auto y: x) {
                config.push_back(y);
                // cout<<y<<" ";
              }
            // cout<<endl;
        }
          
        
        ans.push_back(config);
        return;
      }
      for (int row = 0; row < n; row++) {
        if (leftrow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0) {
          board[row][col] = 1;
          leftrow[row] = 1;
          lowerDiagonal[row + col] = 1;
          upperDiagonal[n - 1 + col - row] = 1;
          solve(col + 1, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
          board[row][col] = 0;
          leftrow[row] = 0;
          lowerDiagonal[row + col] = 0;
          upperDiagonal[n - 1 + col - row] = 0;
        }
      }
}
vector<vector<int>> solveNQueens(int n) {
    vector<vector<int>> board(n, vector<int>(n,0));
    vector<vector<int>> ans;
    vector<int> rows(n, 0), upperDiagonal(2*n-1, 0), lowerDiagonal(2*n-1, 0);
    solve(0, board, ans, rows,upperDiagonal,lowerDiagonal,n);

    return ans;

}