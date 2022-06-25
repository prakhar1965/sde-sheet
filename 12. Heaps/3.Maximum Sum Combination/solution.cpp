// CodeStudio link: https://www.codingninjas.com/codestudio/problems/k-max-sum-combinations_975322?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
// Leetcode link: https://www.interviewbit.com/problems/maximum-sum-combinations/

#include<bits/stdc++.h>
using namespace std;
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
    
    priority_queue<int> max_heap;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            max_heap.push(a[i] + b[j]);
        }
    }
    vector<int>ans;
    while(k--) {
        ans.push_back(max_heap.top());
        max_heap.pop();
    }
    return ans;
}