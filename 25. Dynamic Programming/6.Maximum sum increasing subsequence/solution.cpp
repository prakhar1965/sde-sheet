// CodeStudio link: https://bit.ly/3tqiS0s
// Leetcode link: https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1
int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
    int dp[n+1];
    memset(dp, 0, sizeof(dp));
    int ans = 0;
    for(int i=1; i<=n; i++) 
    {
        dp[i] = rack[i-1];
        for(int j=1; j<i; j++) 
        {
            if(rack[i-1] > rack[j-1])
                dp[i] = max(dp[i], dp[j] + rack[i-1]); 
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}