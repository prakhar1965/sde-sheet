// Solution link: https://takeuforward.org/data-structure/kadanes-algorithm-maximum-subarray-sum-in-an-array/
// CodeStudio link: https://bit.ly/3HZltTa
// Leetcode link: https://leetcode.com/problems/maximum-subarray/

#include <bits/stdc++.h> 
using namespace std;
long long maxSubarraySum(int arr[], int n)
{
    long long globalMaxSum = 0, maxSumAtPreviousI = INT_MIN;

    for(int i=0; i<n; i++)
    {
        long long maxSumAtI = max(maxSumAtPreviousI + arr[i], (long long)arr[i]);
        globalMaxSum = max(globalMaxSum, maxSumAtI);
        maxSumAtPreviousI = maxSumAtI;
    }

    return globalMaxSum;
}

// int main()
// {
//     int arr[] = {1 ,2 ,7, -4, 3, 2, -10, 9 ,1};
//     int n = 9;
//     cout<<maxSubarraySum(arr, 9);
// }