// Solution link: https://takeuforward.org/data-structure/4-sum-find-quads-that-add-up-to-a-target-value/
// CodeStudio link: https://bit.ly/3qpfEsj
// Leetcode link: https://leetcode.com/problems/4sum/

#include <bits/stdc++.h>
using namespace std; 

struct twoSumPair {
    int sum;
    int x1;
    int x2;
};

int notCommon( twoSumPair a,  twoSumPair b) {
    if(a.x1 == b.x1 || a.x2 == b.x1 || a.x1 == b.x2 || a.x2 == b.x2) 
        return 0;
    return 1;
}

string fourSum(vector<int> arr, int target, int n) {
    vector<twoSumPair> twoSumArray;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            twoSumArray.push_back(twoSumPair{arr[i] + arr[j], i, j});
        }
    }

    unordered_map<int, twoSumPair> hashMap;
    for(twoSumPair x: twoSumArray) {
        auto itr = hashMap.find(x.sum);
        if(itr != hashMap.end()) {
            if(notCommon(itr->second, x))
                return "Yes";
        }
        hashMap[target-x.sum] = x;
    }
    return "No";
}
