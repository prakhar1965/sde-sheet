// Solution link: https://takeuforward.org/data-structure/implement-stack-using-single-queue/
// CodeStudio link: https://bit.ly/3reLgQs
// Leetcode link: https://leetcode.com/problems/implement-stack-using-queues/
#include<bits/stdc++.h>
using namespace std;
class Stack {
	
    queue<int> q1;
    queue<int> q2;

   public:
    Stack() {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        return q1.size();
    }

    bool isEmpty() {
        return q1.empty();
    }

    void push(int element) {
        q1.push(element);
    }

    int pop() {
        int popElement = -1;
        if(!q1.empty()) {
            while(q1.size() != 1) {
                q2.push(q1.front());
                q1.pop();
            }
            popElement = q1.front();
            q1.pop();
            swap(q1,q2);
        }
        return popElement;
    }

    int top() {
        int topElement = -1;
        if(!q1.empty()) {
            while(q1.size() != 1) {
                q2.push(q1.front());
                q1.pop();
            }
            topElement = q1.front();
            q2.push(q1.front());
            q1.pop();
            swap(q1,q2);
        }
        return topElement;
    }
};