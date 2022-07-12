\// Solution link: https://takeuforward.org/data-structure/longest-common-subsequence-dp-25/
// CodeStudio link: https://bit.ly/3raZbqM
// Leetcode link: https://leetcode.com/problems/longest-common-subsequence/
#include<bits/stdc++.h>
using namespace std;
int lcs(string s, string t)
{
    int n = s.length();
    int m = t.length();

    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    for(int i=0; i<=n; i++) dp[i][0] = 0;
    for(int i=0; i<=m; i++) dp[0][i] = 0;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            
            if(s[i-1] == t[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
//     for(int i=1; i<=n; i++) {
//         for(int j=1; j<=m;j++) {
//             cout<< dp[i][j];
//         }
//         cout<<endl;
//     }
    return dp[n][m];
}