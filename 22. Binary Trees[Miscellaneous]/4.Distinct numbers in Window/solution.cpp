// CodeStudio link: bit.ly/3zYWpcb
// Leetcode link: https://www.interviewbit.com/problems/distinct-numbers-in-window/
#include<bits/stdc++.h>
using namespace std;
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    unordered_map<int,int> hashMap;
    vector<int>ans;
    int n = arr.size();
    for(int i=0; i<k; i++) hashMap[arr[i]]++;
    for(int i=k; i<n; i++) {
        ans.push_back(hashMap.size());
        hashMap[arr[i]]++;
        if(hashMap[arr[i-k]] == 1)
            hashMap.erase(arr[i-k]);
    }   
    ans.push_back(hashMap.size());
    return ans;
}
