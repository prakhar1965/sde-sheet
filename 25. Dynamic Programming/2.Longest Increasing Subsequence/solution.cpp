// CodeStudio link: https://bit.ly/3GuWGpA
// Leetcode link: https://leetcode.com/problems/longest-increasing-subsequence/
#include<bits/stdc++.h>
using namespace std;
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> sub;
        for (int i=0; i<n; i++) {
            if (sub.empty() || sub[sub.size() - 1] < arr[i]) {
                sub.push_back(arr[i]);
            } else {
                auto it = lower_bound(sub.begin(), sub.end(), arr[i]); 
                *it = arr[i]; 
            }
        }
        return sub.size();
}
