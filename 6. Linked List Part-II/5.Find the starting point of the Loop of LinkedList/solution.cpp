// Solution link: https://takeuforward.org/data-structure/starting-point-of-loop-in-a-linked-list/
// CodeStudio link: https://bit.ly/3K32lpf
// Leetcode link: https://leetcode.com/problems/linked-list-cycle-ii/

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

Node *firstNode(Node *head)
{
	if(!head) return head;

    Node* slow = head, *fast = head;
    while(fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {
            Node* start = head, *curr = slow;
            while(start && curr) {
                if(start == curr) return start;
                start = start->next;
                curr = curr->next;
            }
        } 
    }
    return NULL;
}