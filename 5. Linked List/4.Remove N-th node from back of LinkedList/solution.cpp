// Solution link: https://takeuforward.org/data-structure/remove-n-th-node-from-the-end-of-a-linked-list/
// CodeStudio link: https://bit.ly/3riZ4JB
// Leetcode link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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

LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int K)
{  if(!head || K == 0) return head;
   LinkedListNode<int> *start = new LinkedListNode<int>(-1);
    start->next = head;
    LinkedListNode<int> *kthNode = start;
    for(int i=1; i<=K; i++)
        kthNode = kthNode->next;
    LinkedListNode<int> *curr = start;
    while(kthNode->next != NULL) {
        kthNode = kthNode->next;
        curr = curr->next;
    }
    curr->next = curr->next->next;
    return start->next;
}

