// CodeStudio link: https://bit.ly/3qnFoFg
// Leetcode link: https://leetcode.com/problems/copy-list-with-random-pointer/
#include <bits/stdc++.h> 
/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    if(!head) return head;
    LinkedListNode<int> *curr = head;
    while(curr) {
        LinkedListNode<int>* temp = curr->next;
        curr->next = new LinkedListNode<int>(curr->data);
        curr->next->next = temp;
        curr = temp;
    }
    curr = head;
    while(curr && curr->next) {
        LinkedListNode<int> *ran = curr->random? curr->random->next: curr->random;
        curr->next->random = ran;
        curr = curr->next->next;
    }  
    LinkedListNode<int> * copy = head->next, *copyHead = head->next;
    curr = head;
    while(curr && copy) {
        curr->next = curr->next? curr->next->next: NULL;
        copy->next = copy->next? copy->next->next: NULL;
        curr = curr->next;
        copy = copy->next;
    }
    return copyHead;
}
