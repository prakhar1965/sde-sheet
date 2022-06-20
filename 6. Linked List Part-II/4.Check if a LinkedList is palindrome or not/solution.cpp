// Solution link: https://takeuforward.org/data-structure/check-if-given-linked-list-is-plaindrome/
// CodeStudio link: https://bit.ly/3GqRMKv
// Leetcode link: https://leetcode.com/problems/palindrome-linked-list/

#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/
bool isPalindromeUtil(LinkedListNode<int>* &left, LinkedListNode<int>* right) {
    if(!right) return true;
    bool isSubPalindrome = isPalindromeUtil(left, right->next);
    if(!isSubPalindrome) return false;
    bool isPalindrome = left->data == right->data;
    left = left->next;
    return isPalindrome; 
}
bool isPalindrome(LinkedListNode<int> *head) {
    if(!head) return true;
    return isPalindromeUtil(head, head);
}

// Iterative way
// 1. find middle point
// 2. reverse linked list after middle point
// 3. Check palindrome