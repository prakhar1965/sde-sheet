// Solution link: https://takeuforward.org/data-structure/count-inversions-in-an-array/
// CodeStudio link: https://bit.ly/339fFb7
// Leetcode link: https://www.codingninjas.com/codestudio/problems/count-inversions_615

#include <bits/stdc++.h>
using namespace std;
long long getInversionHelper(long long * &arr, int start, int end) {
    if(start < end) {
        int mid = (start+end)/2;
        long long leftCnt =  getInversionHelper(arr,start,mid);
        long long rightCnt = getInversionHelper(arr,mid+1,end); 
        
        long long cnt = 0;
        int i = start, j = mid+1;
        vector<long long>tempArr;
        while(i<=mid && j<=end) {
            if(arr[i] <= arr[j]) {
                tempArr.push_back(arr[i]);
                
                i++;
            } else {
                tempArr.push_back(arr[j]);
                cnt += (mid+1) - i;
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

long long getInversions(long long *arr, int n){
    
    return getInversionHelper(arr,0,n-1);

}

// int main(){
//     long long arr[] = {2, 5, 1, 3, 4};
//     getInversions(arr, 5);
// }