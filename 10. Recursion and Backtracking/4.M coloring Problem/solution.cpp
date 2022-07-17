// Solution link: https://takeuforward.org/data-structure/m-coloring-problem/
// CodeStudio link: https://bit.ly/3I48oI6
// Leetcode link: https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1#
#include<bits/stdc++.h>
using namespace std;

bool isSafe(int v, vector<vector<int>> &mat, int m, vector<int>&colour, int col) {
    for(int i=0; i<mat.size(); i++) {
        if(v != i && mat[v][i] == 1 && col == colour[i])
            return false;
    }
    return true;
} 
bool dfs(int v, vector<vector<int>> &mat, int m, vector<int>&colour) 
{
    if(v == mat.size())
        return true;
    for(int i=1; i<=m; i++) {
        if(isSafe(v, mat, m, colour, i)) {
            colour[v] = i;
            if(dfs(v+1, mat, m, colour)) return true;
            colour[v] = 0;
        }
    }
    return false;
}

string graphColoring(vector<vector<int>> &mat, int m) {
    int n = mat.size();
    
    vector<int>colour(n,0);
    bool isPossible =  dfs(0,mat, m, colour);
    return isPossible? "YES" : "NO";
}