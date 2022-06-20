// Solution link: https://takeuforward.org/data-structure/count-maximum-consecutive-ones-in-the-array/
// CodeStudio link: https://leetcode.com/problems/max-consecutive-ones/
// Leetcode link: https://leetcode.com/problems/max-consecutive-ones/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int lenConOnes = 0,currLen = 0;
        for(int x: nums) {
            if(x) currLen++;
            else {
                lenConOnes = max(lenConOnes, currLen);
                currLen = 0;
            }
        }
        return max(lenConOnes, currLen);
    }
};