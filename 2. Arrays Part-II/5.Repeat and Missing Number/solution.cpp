// Solution link: https://takeuforward.org/data-structure/find-the-repeating-and-missing-numbers/
// CodeStudio link: https://bit.ly/3Gs6wZu
// Leetcode link: https://www.interviewbit.com/problems/repeat-and-missing-number-array/

#include <bits/stdc++.h> 
using namespace std;
pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{     int missingNo, repeatingNo;
	  for(int i=0; i<n; i++) {
        int idx = abs(arr[i]) -1;
        if(arr[idx] < 0)
        repeatingNo = idx+1;
        else
        arr[idx] = -arr[idx];
    }

    for(int i=0; i<n; i++) {
        if(arr[i] > 0) {
            missingNo = i+1;
        }
    }
	return {missingNo, repeatingNo};
}
