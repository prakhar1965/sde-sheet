// Solution link: https://takeuforward.org/data-structure/rotate-a-linked-list/
// CodeStudio link: https://bit.ly/33bNQPo
// Leetcode link: https://leetcode.com/problems/rotate-list/description/

#include <bits/stdc++.h> 
/********************************

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

********************************/

int findLength(Node* head) {
    int cnt = 0;
    while(head) {head = head->next; cnt++;}
    return cnt;
}

Node *rotate(Node *head, int k) {
    if(k == 0) return head;
    int len = findLength(head);
    Node *curr = head;
    Node *curr2 = curr;
    k = k%len; 
    while(k>0 && curr2->next) {
        curr2 = curr2->next;
        k--;
    }
    while(curr2->next) {
        curr2 = curr2->next;
        curr = curr->next;
    }
    curr2->next = head;
    Node *newHead = curr->next;
    curr->next = NULL;
    return newHead;
}

  