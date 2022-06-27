// CodeStudio link: https://bit.ly/3K6WVtb
// Leetcode link: https://www.interviewbit.com/problems/nearest-smaller-element/
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int>s;
    s.push(-1);
    vector<int> ans(n);
    for(int i=n-1; i>=0; i--) {
        if(s.size() == 1) {
            ans[i] = s.top();
        }
        else {
            while(s.size() != 1 && arr[i] <= s.top()) {
                s.pop();
            }
            ans[i] = s.top();
        }
        s.push(arr[i]);
    }
    return ans;
}