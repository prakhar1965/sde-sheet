// Solution link: https://takeuforward.org/data-structure/implement-queue-using-stack/
// CodeStudio link: https://bit.ly/3reLeIk
// Leetcode link: https://leetcode.com/problems/implement-queue-using-stacks/
#include<bits/stdc++.h>
using namespace std;
class Queue {
    // Define the data members(if any) here.
    stack<int>s1, s2;
    public:
    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) {
        s1.push(val);
    }

    int deQueue() {
        int popElement = -1;
        if(!s2.empty()) {
            popElement = s2.top();
            s2.pop();
        } else {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
            if(!s2.empty()) {
                popElement = s2.top();
                s2.pop();
            }
        }
        return popElement;
    }

    int peek() {
        int peek = -1;
        if(!s2.empty()) {
            peek = s2.top();
        } else {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
            if(!s2.empty()) {
                peek = s2.top();
            }
        }
        return peek;
    }

    bool isEmpty() {
        return s1.empty() && s2.empty();
    }
};