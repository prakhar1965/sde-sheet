// Solution link: https://takeuforward.org/data-structure/coin-change-2-dp-22/
// CodeStudio link: https://bit.ly/3GwBrnA
// Leetcode link: https://leetcode.com/problems/coin-change/
#include<bits/stdc++.h>
using namespace std;
long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>> dp(n+1, vector<long>(value+1, 0));
    dp[0][0] = 1LL;
    for(int i=1; i<=n; i++) {
        for(int j=0; j<=value; j++) {
            if(j >= denominations[i-1])
                dp[i][j] += dp[i][j-denominations[i-1]];
                dp[i][j] += dp[i-1][j];
        }
    }
    return dp[n][value];
}