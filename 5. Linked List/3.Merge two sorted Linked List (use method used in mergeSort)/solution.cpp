// Solution link: https://takeuforward.org/data-structure/merge-two-sorted-linked-lists/
// CodeStudio link: https://bit.ly/3qnbSj8
// Leetcode link: https://leetcode.com/problems/merge-two-sorted-lists/

#include <bits/stdc++.h> 
/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{   if(!first) return second;
    if(!second) return first;
    if(first->data > second->data) std::swap(first, second);   
    Node<int>* head = first;

    while(first && second) {
        Node<int> *temp = NULL;
        while(first && first->data <= second->data) {
            temp = first;
            first = first->next;
        }
        temp->next = second;
        std::swap(first, second);
    }
    return head;
}
