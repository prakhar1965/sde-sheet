// CodeStudio link: https://bit.ly/3qqX56T
// Leetcode link: https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1
#include<bits/stdc++.h>
using namespace std;

int matrixMultiplication(vector<int> &arr, int N)
{
    int dp[N][N];
    memset(dp, 0, sizeof(dp));
    for(int len=2; len<N; len++) {
        for(int i=0; i+len<N; i++) {
            dp[i][i+len-1] = INT_MAX;
            for(int k=i+1; k<i+len;k++) {
                dp[i][i+len-1] = min(dp[i][i+len-1],dp[i][k-1] + dp[k][i+len-1] + arr[i]*arr[i+len]*arr[k]);
            }
        }
    }
    return dp[0][N-2];
}