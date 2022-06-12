// Solution link: https://takeuforward.org/data-structure/majority-elementsn-3-times-find-the-elements-that-appears-more-than-n-3-times-in-the-array/
// CodeStudio link: https://bit.ly/3foYLYp
// Leetcode link: https://leetcode.com/problems/majority-element-ii/

#include <bits/stdc++.h>
using namespace std; 
vector<int> majorityElementII(vector<int> &arr)
{
    int maj1 = -1,cnt1 = 0, maj2 = -1, cnt2 = 0;

    for(int i=0; i<arr.size(); i++)
    {
        if(maj1 == arr[i]) cnt1++;
        else if(maj2 == arr[i]) cnt2++;
        else if(cnt1 == 0) {maj1 = arr[i]; cnt1++;}
        else if(cnt2 == 0) {maj2 = arr[i]; cnt2++;}
        else {
            cnt1--;
            cnt2--;
        } 
    }
    vector<int> majElements;
    cnt1 = 0;
    cnt2 = 0;
    for(int x: arr) {
        if(x == maj1) cnt1++;
        if(x == maj2) cnt2++;
    }
    int majCnt = arr.size()/3;
    if(cnt1 > majCnt) majElements.push_back(maj1);
    if(cnt2 > majCnt) majElements.push_back(maj2);

    return majElements;
}