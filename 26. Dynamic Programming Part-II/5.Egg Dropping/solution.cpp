// CodeStudio link: https://bit.ly/3A6id5O
// Leetcode link: https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1
#include<bits/stdc++.h>
using namespace std;
int cutLogs(int K, int N)
{
    vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
        int m = 0;
        while (dp[m][K] < N) {
            m++;
            for (int k = 1; k <= K; ++k)
                dp[m][k] = dp[m - 1][k - 1] + dp[m - 1][k] + 1;
        }
        return m;
}
