// Solution link: https://takeuforward.org/data-structure/merge-two-sorted-arrays-without-extra-space/
// CodeStudio link: https://bit.ly/33umm7e
// Leetcode link: https://leetcode.com/problems/merge-sorted-array/

#include <bits/stdc++.h>
using namespace std; 
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
    int i = m-1, j = n-1;
    int curr = m+n-1;
    while(i>=0 && j>=0) {

       if(arr1[i] > arr2[j]) {
        arr1[curr--] = arr1[i--];
       } else {
        arr1[curr--] = arr2[j--];
       }
    }

    while(i>=0) {
        arr1[curr--] = arr1[i--];
    }

    while(j>=0) {
        arr1[curr--] = arr2[j--];
    }
    return arr1;
}