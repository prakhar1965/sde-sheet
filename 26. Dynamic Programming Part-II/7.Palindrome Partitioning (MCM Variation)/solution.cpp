// CodeStudio link: https://bit.ly/3tq9MRn
// Leetcode link: https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1
#include<bits/stdc++.h>
using namespace std;
int palindromePartitioning(string str) {
    int n = str.length();
    int dp[n];
    vector<vector<bool>> pal(n, vector<bool>(n, 0));

    for(int i=0; i<n; i++) {
        int min = i;
        for(int j=0; j<=i; j++) {
            if(str[j] == str[i] && (j+1>i-1 || pal[j+1][i-1])) {
                pal[i][j] = 1;
                min = (j == 0) ? 0 : dp[j-1]+1;
            }
        }
        dp[i] = min;
    }
    return dp[n-1];
}
