// Solution link: https://takeuforward.org/data-structure/reverse-linked-list-in-groups-of-size-k/
// CodeStudio link: https://bit.ly/3Gsfk1u
// Leetcode link: https://leetcode.com/problems/reverse-nodes-in-k-group/

#include <bits/stdc++.h> 
using namespace std;
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

int lenOfLinkedList(Node* head) {
    int cnt = 0;
    while(head){
        head = head->next;
        cnt++;
    }
    return cnt;
}
Node *getListAfterReverseOperation(Node *head, int n, int b[]){
    Node * prevHead = new Node(-1);
    int len = lenOfLinkedList(head);
    prevHead->next = head;
    Node* prev = prevHead, *curr, *nex;
    int i = 0;
    while(len > 0) {
        curr = prev->next;
        nex = curr->next;
        int l = min(b[i], len);
        for(int j=1; j<l; j++) {
            curr->next = nex->next;
            nex->next = prev->next;
            prev->next = nex;
            nex = curr->next;
        }
        if(l>0) prev = curr;
        len -= b[i];
        i++;
        if(i==n) break;
    }

  
    return prevHead->next;
}



