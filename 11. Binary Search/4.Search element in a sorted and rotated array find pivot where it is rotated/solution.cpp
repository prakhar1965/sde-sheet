// Solution link: https://takeuforward.org/data-structure/search-element-in-a-rotated-sorted-array/
// CodeStudio link: https://bit.ly/3nnxGcm
// Leetcode link: https://leetcode.com/problems/search-in-rotated-sorted-array/

int search(int* arr, int n, int key) {
    int low = 0, high = n-1;
    while(low <= high) {
        int mid = (low+high)/2;
        if(arr[mid] == key) return mid;
        if(arr[low] <= arr[mid]) {
            if(key >= arr[low] && key <= arr[mid]) high = mid;
            else low = mid+1;
        } else {
            if(key >= arr[mid] && key <= arr[high]) low = mid;
            else high = mid-1;
        }
    }   
    return -1; 
}