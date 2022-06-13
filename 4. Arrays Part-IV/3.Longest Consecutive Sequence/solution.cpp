// Solution link: https://takeuforward.org/data-structure/longest-consecutive-sequence-in-an-array/
// CodeStudio link: https://bit.ly/34EoAS0
// Leetcode link: https://leetcode.com/problems/longest-consecutive-sequence/

#include <bits/stdc++.h>
using namespace std; 
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {

    unordered_set<int> hashSet;
    for(int x:arr) hashSet.insert(x);

    int maxSeq = 0;

    for(int x: arr) {
        if(!hashSet.count(x-1)) {
            int currSeq = 1;
            while(hashSet.count(x+1)) {x++; currSeq++;}
            maxSeq = max(maxSeq, currSeq);
        }
    }
    return maxSeq;
}
