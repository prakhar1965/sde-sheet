// Solution link: https://takeuforward.org/data-structure/find-the-duplicate-in-an-array-of-n1-integers/
// CodeStudio link: https://bit.ly/3GtKDJb
// Leetcode link: https://leetcode.com/problems/find-the-duplicate-number/

#include <bits/stdc++.h> 
using namespace std;
int findDuplicate(vector<int> &arr, int n){
	
    for(int i=0; i<n; i++) {
        int idx = abs(arr[i]) -1;
        if(arr[idx] < 0)
        return idx+1;
        else
        arr[idx] = -arr[idx];
    }
}