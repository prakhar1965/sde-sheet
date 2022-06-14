// Solution link: https://takeuforward.org/data-structure/add-two-numbers-represented-as-linked-lists/
// CodeStudio link: https://bit.ly/3qqbgcq
// Leetcode link: https://leetcode.com/problems/add-two-numbers/

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

Node *addTwoNumbers(Node *head1, Node *head2)
{
    int carry = 0;

    Node* curr1 = head1, *curr2 = head2, *head = NULL, *curr3 = head;
    while(curr1 || curr2) {
        int x = carry;
        if(curr1) x += curr1->data;
        if(curr2) x += curr2->data;
        carry = x/10;
        if(!head) {
            head = new Node(x%10);
            curr3 = head;
        } else {
            curr3->next = new Node(x%10);
            curr3 = curr3->next;
        }
        if(curr1) curr1 = curr1->next;
        if(curr2) curr2 = curr2->next;
    }
    if(carry != 0)
        curr3->next = new Node(carry);
    return head;
}