// Solution link: https://takeuforward.org/data-structure/count-the-number-of-subarrays-with-given-xor-k/
// CodeStudio link: https://bit.ly/3fp24yN
// Leetcode link: https://www.interviewbit.com/problems/subarray-with-given-xor/

#include <bits/stdc++.h> 
using namespace std;
int subarraysXor(vector<int> &arr, int x)
{
    unordered_map<int,int> hashMap;
    hashMap[0] = 1;
    int prefixXor = 0, subArrXor = 0;
    for(int a: arr) {
        prefixXor ^= a;
        auto itr = hashMap.find(prefixXor^x);
        if(itr != hashMap.end()) {
            subArrXor += itr->second;
        }
        hashMap[prefixXor]++;
    }
    return subArrXor;
}