// Solution link: https://takeuforward.org/data-structure/0-1-knapsack-dp-19/
// CodeStudio link: https://bit.ly/3FvHbMO
// Leetcode link: https://leetcode.com/problems/ones-and-zeroes/
#include<bits/stdc++.h>
using namespace std;
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
    int dp[n+1][w+1];
    for(int i=0; i<=n; i++) dp[i][0] = 0;
    for(int i=0; i<=w; i++) dp[0][i] = 0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=w; j++) {
            dp[i][j] = dp[i-1][j];
            if(j - weights[i-1] >= 0) 
                dp[i][j] = max(dp[i][j], dp[i-1][j-weights[i-1]] + values[i-1]);
        }
    }
    return dp[n][w];
}