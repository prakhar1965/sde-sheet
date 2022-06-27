// CodeStudio link: https://bit.ly/3nptF7k
#include<bits/stdc++.h>
using namespace std;
void insertInSortedStack(stack<int>& stack, int val) {
    if(stack.empty() || stack.top() <= val) {
        stack.push(val);
    } else {
        int ele = stack.top();
        stack.pop();
        insertInSortedStack(stack,val);
        stack.push(ele);
    }
}
void sortStack(stack<int> &stack)
{
    if(!stack.empty()) {
        int ele = stack.top();
        stack.pop();
        sortStack(stack);
        insertInSortedStack(stack,ele);
    }  
}