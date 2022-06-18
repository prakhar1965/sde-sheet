// Solution link: https://takeuforward.org/data-structure/detect-a-cycle-in-a-linked-list/
// CodeStudio link: https://bit.ly/3I2fmxh
// Leetcode link: https://leetcode.com/problems/linked-list-cycle/

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

bool detectCycle(Node *head)
{
    Node* slow = head, *fast = head;

    while(fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) 
        {
            return true;
        }
    }
    return false;
}