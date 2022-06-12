// Solution link: https://takeuforward.org/data-structure/count-reverse-pairs/
// CodeStudio link: https://bit.ly/3tm5PgF
// Leetcode link: https://leetcode.com/problems/reverse-pairs/

#include <bits/stdc++.h>
using namespace std;

int reversePairHelper(vector<int>& arr, int start, int end) {
    if(start < end) {
        int mid = (start+end)/2;
        long long leftCnt =  reversePairHelper(arr,start,mid);
        long long rightCnt = reversePairHelper(arr,mid+1,end); 
        
        long long cnt = 0;
        int j = mid+1;
        for(int i=start; i<=mid; i++) {
            while(j <= end && arr[i] > 2*arr[j]) j++;

            cnt += (j-mid-1);
        }
        int i = start;
         j = mid+1;
        vector<long long>tempArr;
        while(i<=mid && j<=end) {
            if(arr[i] <= arr[j]) {
                tempArr.push_back(arr[i]);
                
                i++;
            } else {
                tempArr.push_back(arr[j]);
                j++;
            }
        }
        while(i<=mid) tempArr.push_back(arr[i++]);
        while(j<=end) tempArr.push_back(arr[j++]);

        for(int i=0;i<=end-start;i++) {
            arr[start+i] = tempArr[i];
        }

        return leftCnt+cnt+rightCnt;
    }
    return 0;
}
int reversePairs(vector<int> &arr, int n){
	return reversePairHelper(arr,0,n-1);	
}