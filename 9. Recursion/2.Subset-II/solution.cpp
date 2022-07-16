// Solution link: https://takeuforward.org/data-structure/subset-ii-print-all-the-unique-subsets/
// CodeStudio link: https://bit.ly/3qnaLjq
// Leetcode link: https://leetcode.com/problems/subsets-ii/
#include<bits/stdc++.h>
using namespace std;
void generatePowerSet(int idx, vector<int> &v, vector<vector<int>> &powerSet, vector<int> &currSet) {
    powerSet.push_back(currSet);
    for(int i=idx; i<v.size(); i++) {
        currSet.push_back(v[i]);
        generatePowerSet(i+1,v,powerSet, currSet);
        currSet.pop_back();
    }
}
vector<vector<int>> pwset(vector<int>v)
{
     sort(v.begin(), v.end());
    int n = v.size();
 
    vector<vector<int>> powerSet;
    vector<int>currSet;
    generatePowerSet(0, v, powerSet, currSet);
    return powerSet;
}