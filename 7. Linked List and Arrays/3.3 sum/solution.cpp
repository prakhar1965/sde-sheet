// Solution link: https://takeuforward.org/data-structure/3-sum-find-triplets-that-add-up-to-a-zero/
// CodeStudio link: https://bit.ly/33wlWxk
// Leetcode link: https://leetcode.com/problems/3sum/
#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
    vector<vector<int>> triplets;
    sort(arr.begin(), arr.end());
    for(int i=0; i<n-2; i++) {
        int s = K - arr[i];
        int start = i+1, end = n-1;
        while(start<end) {
            int x = arr[start]+arr[end];
            if(x > s) end--;
            else if(x < s) start++;
            else {
                triplets.push_back({arr[i], arr[start], arr[end]});
                
                while(start+1<n && arr[start] == arr[start+1]) start++;
                while(end-1>=0 && arr[end] == arr[end-1]) end--;
                start++;end--;
            }
        }
        while(i+1 < n && arr[i] == arr[i+1]) i++;
    }
    return triplets;
}

 