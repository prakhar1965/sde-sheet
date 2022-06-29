    // Solution link: https://takeuforward.org/data-structure/sliding-window-maximum/
    // CodeStudio link: https://bit.ly/3GmTkoC
    // Leetcode link: https://leetcode.com/problems/sliding-window-maximum/
    #include<bits/stdc++.h>
    using namespace std;
    #define pi pair<int,int>

    struct comp{
    bool operator()(pi &a, pi &b) {
        return a.second<b.second;
    }
    };

    vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
    {   
        int n = nums.size();
        vector<int>ans;
        priority_queue<pi, vector<pi>, comp> max_heap;
        for(int i=0; i<k; i++) {
            max_heap.push(make_pair(i, nums[i]));
        }
        ans.push_back(max_heap.top().second);
        for(int i=k; i<n; i++) {
            int start = i-k+1;
            while(max_heap.size() != 0 && max_heap.top().first < start) max_heap.pop();
            max_heap.push(make_pair(i, nums[i]));
            ans.push_back(max_heap.top().second);
        }
        return ans;
    }