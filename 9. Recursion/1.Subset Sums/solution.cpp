// Solution link: https://takeuforward.org/data-structure/subset-sum-sum-of-all-subsets/
// Leetcode link: https://practice.geeksforgeeks.org/problems/subset-sums2234/1
// codestudio: https://www.codingninjas.com/codestudio/problems/subset-sum_3843086?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
#include<bits/stdc++.h>
using namespace std;
void subSetSumUtil(vector<int>& nums, int curr, vector<int> &ans, int sum) {
    if(curr == nums.size()) 
        {ans.push_back(sum); return;}
    subSetSumUtil(nums, curr+1, ans, sum+nums[curr]);

    subSetSumUtil(nums, curr+1, ans, sum);
}
vector<int> subsetSum(vector<int> &num)
{   vector<int> ans;
    subSetSumUtil(num, 0, ans, 0);
    sort(ans.begin(),ans.end());
    return ans;
}

