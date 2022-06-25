// Solution link: https://takeuforward.org/data-structure/combination-sum-ii-find-all-unique-combinations/
// CodeStudio link: https://bit.ly/3tkbtjk
// Leetcode link: https://leetcode.com/problems/combination-sum-ii/
#include<bits/stdc++.h>
using namespace std;
void findSubSetUtil(int idx,vector<int> &arr, int k, vector<vector<int>> &subSets, vector<int> &curr_set)
{   if(k == 0) {
    sort(curr_set.begin(), curr_set.end()); 
    subSets.push_back(curr_set);
    }
    for(int i=idx;i<arr.size(); i++) {
        if(i != idx && arr[i] == arr[i-1]) continue;
        curr_set.push_back(arr[i]);
        findSubSetUtil(i+1, arr, k-arr[i], subSets, curr_set);
        curr_set.pop_back();
    }
    
}
vector<vector<int>> combinationSum2(vector<int> arr, int n, int k)
{
    vector<vector<int>> subSets;
    vector<int>curr_set;
    sort(arr.begin(), arr.end());
    findSubSetUtil(0, arr,k, subSets, curr_set);
    sort(subSets.begin(), subSets.end());
    return subSets;
}