// CodeStudio link: https://bit.ly/3GvQttz
// Leetcode link: https://leetcode.com/problems/kth-largest-element-in-an-array/
int kthLargest(vector<int>& arr, int size, int K)
{
	int start = 0, end = size-1;
    while(start < end) {
        int x = arr[end];
        int i = start-1;
        for(int j=start; j<end; j++) {
            if(arr[j] < x) {
                i++;
                swap(arr[j], arr[i]);
            }
        }
        swap(arr[i+1], arr[end]);
        if(i+1 == n-k) return arr[i+1];
        if(i+1 < n-k) start = i+2;
        else end = i;
    } 
    return -1;
}