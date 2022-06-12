// Solution link: https://takeuforward.org/data-structure/find-the-majority-element-that-occurs-more-than-n-2-times/
// CodeStudio link: https://bit.ly/3FpfpBQ
// Leetcode link: https://leetcode.com/problems/majority-element/

#include <bits/stdc++.h> 
int findMajorityElement(int arr[], int n) {
	int cnt = 0, majElement;
    for(int i=0; i<n; i++) {
        if(cnt == 0) {
            majElement = arr[i];
        } 
            if(arr[i] == majElement) cnt++;
            else cnt--;
     }
    
    int majCnt =0;
    for(int i=0; i<n; i++) {
        if(arr[i] == majElement) majCnt++;
    }
    if(majCnt <= (n/2))
        return -1;
    return majElement;
}