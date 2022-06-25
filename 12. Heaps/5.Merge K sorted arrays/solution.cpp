// CodeStudio link: https://www.codingninjas.com/codestudio/problems/merge-k-sorted-arrays_975379?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
// Leetcode link: https://www.codingninjas.com/codestudio/problems/merge-k-sorted-arrays_975379
#include<bits/stdc++.h>
using namespace std;
#define pipii pair<int,pair<int,int>>
struct comp{
    bool operator()(pipii &a, pipii &b){
        return a.first>b.first;
    }
};
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    vector<int>mergeArray;
    priority_queue<pipii,vector<pipii>,comp> min_heap;
    for(int i=0; i<k; i++) {
       min_heap.push({kArrays[i][0], {i,0}});
    }
    while(!min_heap.empty()) {
        pipii top = min_heap.top();
        min_heap.pop();
        mergeArray.push_back(top.first);
        int i = top.second.first, j = top.second.second;
        if(j+1 < kArrays[i].size()) {
            min_heap.push({kArrays[i][j+1], {i,j+1}});
        }
    }
    return mergeArray;
}

