// Solution link: https://takeuforward.org/data-structure/two-sum-check-if-a-pair-with-given-sum-exists-in-array/
// CodeStudio link: https://bit.ly/3riXBmz
// Leetcode link: https://leetcode.com/problems/two-sum/

#include <bits/stdc++.h> 
using namespace std;
vector<vector<int>> pairSum(vector<int> &arr, int s){
    vector<vector<int>> pairs;

    unordered_map <int,int> hashMap;

    for(int x: arr) {
        auto itr = hashMap.find(x);
        if(itr != hashMap.end()) {
            vector<int> pair = {s-x, itr->first};
            sort(pair.begin(),pair.end());
            for(int i=1; i<= itr->second; i++)
                pairs.push_back(pair);
        }
        hashMap[s-x]++;
    }
    sort(pairs.begin(), pairs.end());
    return pairs;
}