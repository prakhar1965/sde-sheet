// Solution link: https://takeuforward.org/data-structure/combination-sum-1/
// CodeStudio link: https://bit.ly/3qpmDS1
// Leetcode link: https://leetcode.com/problems/combination-sum/
#include<bits/stdc++.h>
using namespace std;
void findSubSetUtil(int idx,vector<int> &arr, int k, vector<vector<int>> &subSets, vector<int> &curr_set)
{   if(idx == arr.size()) {
    if(k == 0 && curr_set.size() != 0)  subSets.push_back(curr_set);
    return;}
    
    findSubSetUtil(idx+1, arr, k, subSets, curr_set); 

    curr_set.push_back(arr[idx]);
    findSubSetUtil(idx+1, arr, k-arr[idx], subSets, curr_set);
    curr_set.pop_back();
    
}
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<vector<int>> subSets;
    vector<int>curr_set;
    findSubSetUtil(0, arr,k, subSets, curr_set);
    
    return subSets;
}