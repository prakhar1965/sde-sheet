// Solution link: https://takeuforward.org/data-structure/rod-cutting-problem-dp-24/
// CodeStudio link: https://bit.ly/3GuIsoS
// Leetcode link: https://leetcode.com/problems/minimum-cost-to-cut-a-stick/
#include<bits/stdc++.h>
using namespace std;
int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            dp[i][j] = dp[i-1][j];
            if(j >= i)
                dp[i][j] = max(dp[i][j],dp[i][j-i] + price[i-1]) ;
        }
    }
    return dp[n][n];
}
