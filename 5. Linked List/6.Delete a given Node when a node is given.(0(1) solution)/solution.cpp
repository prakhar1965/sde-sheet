// Solution link: https://takeuforward.org/data-structure/delete-given-node-in-a-linked-list-o1-approach/
// CodeStudio link: https://bit.ly/3GqW4kN
// Leetcode link: https://leetcode.com/problems/delete-node-in-a-linked-list/

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

void deleteNode(LinkedListNode<int> * node) {
    if(node->next) {
        node->data = node->next->data;
        node->next = node->next->next;
    } else {
        node = NULL;
    }
}