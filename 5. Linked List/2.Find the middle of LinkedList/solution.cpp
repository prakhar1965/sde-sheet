// Solution link: https://takeuforward.org/data-structure/find-middle-element-in-a-linked-list/
// CodeStudio link: https://bit.ly/3KcRxoG
// Leetcode link: https://leetcode.com/problems/middle-of-the-linked-list/

#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

       class Node 
        { 
        public:
            int data;
            Node *next;
            Node(int data) 
            {
               this->data = data;
              this->next = NULL;
            }
        };

*****************************************************************/

Node *findMiddle(Node *head) {
    if(head) {
        Node* slow = head, *fast = head;

        while(fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        if(fast->next) slow = slow->next;
        return slow;
    }
    return head;
}

