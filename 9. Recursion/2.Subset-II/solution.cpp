// Solution link: https://takeuforward.org/data-structure/subset-ii-print-all-the-unique-subsets/
// CodeStudio link: https://bit.ly/3qnaLjq
// Leetcode link: https://leetcode.com/problems/subsets-ii/
#include<bits/stdc++.h>
void uniqueSubsetUtil(int idx,vector<int>& arr, vector<int>&curr_set,vector<vector<int>> &ans) {
    ans.push_back(curr_set);
    for(int i=idx;i<arr.size(); i++) {
        if(i != idx && arr[i] == arr[i-1]) continue;
        curr_set.push_back(arr[i]);
        uniqueSubsetUtil(i+1, arr, curr_set, ans);
        curr_set.pop_back();
    }
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    vector<vector<int>> ans;
    vector<int> curr_set;
    sort(arr.begin(), arr.end());
    uniqueSubsetUtil(0, arr, curr_set, ans);
    return ans;
}