// Solution link: https://takeuforward.org/data-structure/length-of-longest-substring-without-any-repeating-character/
// CodeStudio link: https://bit.ly/3no44fb
// Leetcode link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
#include <bits/stdc++.h>
using namespace std; 
int uniqueSubstrings(string input)
{
    int len = input.length();
    unordered_map<char, int> hashMap;
    int maxLen = 0,currLen = -1;
    for(int i=0; i<len; i++) {
        auto itr = hashMap.find(input[i]);
        if(itr != hashMap.end()) {
            if(itr->second >= currLen) {
                currLen = itr->second;
            }
        }
        maxLen = max(maxLen, i - currLen);
        hashMap[input[i]] = i;
    }
    return maxLen;
}