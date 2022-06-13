// Solution link: https://takeuforward.org/data-structure/reverse-a-linked-list/
// CodeStudio link: https://bit.ly/3qoE6K6
// Leetcode link: https://leetcode.com/problems/reverse-linked-list/

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

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    LinkedListNode<int> *prev = NULL, *curr = NULL, *head1 = head;
    while(head1)
    {
        curr = head1;
        head1 = head1->next;
        curr->next = prev;
        prev = curr;
    }
    return head = curr;
}