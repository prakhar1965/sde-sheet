// Solution link: https://takeuforward.org/data-structure/subset-sum-equal-to-target-dp-14/
// CodeStudio link: https://bit.ly/3rjUdb7
// Leetcode link: https://leetcode.com/problems/partition-equal-subset-sum/
#include<bits/stdc++.h>
using namespace std;
bool subsetSumToK(int n, int k, vector<int> &arr) {
   vector<vector<bool>> dp(n+1, vector<bool>(k+1, 0));
   dp[0][0] = 1;
   for(int i=1; i<=n; i++) {
      for(int j=0; j<=k; j++) {
        dp[i][j] = d[i-1][j];
        if(j >= arr[i-1])
            dp[i][j] = dp[i][j] || dp[i-1][j-arr[i-1]];
      }
   }
   return dp[n][k];
}