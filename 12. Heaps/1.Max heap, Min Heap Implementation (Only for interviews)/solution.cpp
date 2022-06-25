    // CodeStudio link: https://www.codingninjas.com/codestudio/problems/min-heap_4691801?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
    #include<bits/stdc++.h>
    using namespace std;
    void bubble_up(vector<int> &min_heap, int pos) {
        while(pos > 0) {
            int parent = (pos-1)/2;
            if(parent >= 0 && min_heap[parent] > min_heap[pos]) {
                swap(min_heap[parent], min_heap[pos]);
                pos = parent;
            } else break;
        }
    }

    void bubble_down(vector<int> &min_heap) {
        int i = 0;
        int n = min_heap.size();
        while(i < n) {
            int left = 2*i+1;
            int right = 2*i+2;
            int smaller = i;
            if(left < n && min_heap[left] < min_heap[smaller]) {
                smaller = left;
            }
            if(right < n && min_heap[right] < min_heap[smaller]) {
                smaller = right;
            }
            if(i == smaller) break;
            swap(min_heap[i], min_heap[smaller]);
            i = smaller;
        }
    }
    vector<int> minHeap(int n, vector<vector<int>>& q) {
        vector<int> ans;
        vector<int> min_heap;
        for(int i=0; i<n; i++) {
            int q1 = q[i][0];
            if(q1 == 0) {
                int x = q[i][1];
                min_heap.push_back(x);
                int pos = min_heap.size() - 1;
                bubble_up(min_heap, pos);
            } else if(q1 == 1) {
                ans.push_back(min_heap[0]);
                min_heap[0] = min_heap[min_heap.size()-1];
                min_heap.pop_back();
                bubble_down(min_heap);
            }
        }
        return ans;
    }

