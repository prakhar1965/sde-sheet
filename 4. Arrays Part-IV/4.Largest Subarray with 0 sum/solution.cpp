// Solution link: https://takeuforward.org/data-structure/length-of-the-longest-subarray-with-zero-sum/
// CodeStudio link: https://bit.ly/31UHoeM
// Leetcode link: https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

#include <bits/stdc++.h> 
using namespace std;
int LongestSubsetWithZeroSum(vector<int> arr) {
    int n = arr.size();
    unordered_map<int,int> hashMap;
    hashMap[0] = -1;
    int prefixSum = 0, maxSet = 0;
    for(int i=0; i<n; i++) {
        prefixSum += arr[i];
        auto itr = hashMap.find(prefixSum);
        if(itr != hashMap.end()) {
            maxSet = max(maxSet, i - itr->second);
        }
        else 
         hashMap[prefixSum] = i; 
    }
    return maxSet;
}