// CodeStudio link: https://www.codingninjas.com/codestudio/problems/k-most-frequent-elements_3167808?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
// Leetcode link: https://leetcode.com/problems/top-k-frequent-elements/
#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
struct comp{
    bool operator()(pi &a, pi &b) {
        if(a.second == b.second) {
            return a.first>b.first;
        } else  
            return a.second<b.second;
    }
};
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{  
    unordered_map<int,int> hashMap;
    for(int x: arr) hashMap[x]++;
    priority_queue<pi, vector<pi>,comp> max_heap;
    for(auto it: hashMap) {
        max_heap.push(it);
    }
    vector<int> ans;
    while(k--) {
        ans.push_back(max_heap.top().first);
        max_heap.pop();
    }
    sort(ans.begin(),ans.end());
    return ans;
}