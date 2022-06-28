// Solution link: https://takeuforward.org/data-structure/implement-min-stack-o2n-and-on-space-complexity/
// Leetcode link: https://leetcode.com/problems/min-stack/
// codestudio link: https://www.codingninjas.com/codestudio/problems/min-stack_3843991?topList=striver-sde-sheet-problems

// Implement class for minStack.
#include<bits/stdc++.h>
using namespace std;
class minStack
{
	// Write your code here.
    stack<int>s;
    stack<int>min_stack;
	
	public:
		
		// Constructor
		minStack() 
		{ 
			// Write your code here.
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			// Write your code here.
            s.push(num);
            if(min_stack.empty()) min_stack.push(num);
            else {
                if(min(min_stack.top(),num) == num) min_stack.push(num);
            }
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{   if(s.empty()) return -1;
			// Write your code here.
            int x = s.top();
            s.pop();
            if(min_stack.top() == x) min_stack.pop();
            return x;
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			// Write your code here.
            return s.empty() ? -1 : s.top();
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			// Write your code here.
            return s.empty() ? -1: min_stack.top();
		}
};