// Solution link: https://takeuforward.org/data-structure/edit-distance-dp-33/
// CodeStudio link: https://bit.ly/3qpUHgE
// Leetcode link: https://leetcode.com/problems/edit-distance/
#include<bits/stdc++.h>
using namespace std;
int editDistance(string str1, string str2)
{
    int n = str1.length();
    int m = str2.length();

    int dp[n+1][m+1];
    memset(dp, 0, sizeof(dp));
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=m; j++) {
            if(i == 0 && j == 0)
                dp[i][j] = 0;
            else if(i == 0)
                dp[i][j] = j;
            else if(j == 0)
                dp[i][j] = i;
            else {
              
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;
                dp[i][j] = min(dp[i][j], dp[i-1][j-1] + 1);
                if(str1[i-1] == str2[j-1])
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
            }
        }
    }
    return dp[n][m];
}