// Solution link: https://takeuforward.org/data-structure/find-intersection-of-two-linked-lists/
// CodeStudio link: https://bit.ly/3fiMQeG
// Leetcode link: https://leetcode.com/problems/intersection-of-two-linked-lists/

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

int findIntersection(Node *firstHead, Node *secondHead)
{
    unordered_set<Node*> hashSet;
    while(firstHead) {
        hashSet.insert(firstHead);
        firstHead = firstHead->next;
    }
    while(secondHead) {
        if(hashSet.count(secondHead)) {
            return secondHead->data;
        }
        secondHead = secondHead->next;
    }
    return -1;
}