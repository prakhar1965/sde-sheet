// Solution link: https://takeuforward.org/data-structure/search-single-element-in-a-sorted-array/
// CodeStudio link: https://bit.ly/3rng2qC
// Leetcode link: https://leetcode.com/problems/single-element-in-a-sorted-array/

int uniqueElement(vector<int> arr, int n)
{
    int low = 0, high = n-1;
    while(low <= high) {
        int mid = (low+high)/2;
        int first = -1, second = -1;
        if(mid+1<n && arr[mid] == arr[mid+1]) {
            first = mid;
            second = mid+1;
        } else if(mid >= 1 && arr[mid] == arr[mid-1]) {
            first = mid-1;
            second = mid;
        } else {
            return arr[mid];
        }
        if((first-low)%2 == 1) high = first - 1;
        else low = second + 1;
    }
    return -1;
}
