// CodeStudio link: https://bit.ly/3K6weoJ
// Leetcode link: https://leetcode.com/problems/valid-anagram/
#include<bits/stdc++.h>
using namespace std;
bool areAnagram(string &str1, string &str2){
    int n = str1.length(), m = str2.length();
    if(n != m) return false;
    unordered_map<char, int> hashMap;
    for(int i=0; i<n; i++) hashMap[str1[i]]++;

    for(int i=0; i<m; i++) {
        if(hashMap[str2[i]] <= 0) return false;

        hashMap[str2[i]]--; 
    }
    return true;
}