// Solution link: https://takeuforward.org/data-structure/flattening-a-linked-list/
// CodeStudio link: https://bit.ly/3nqtEA1
// Leetcode link: https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1

#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

class Node {
public:
    int data;
    Node* next;
    Node* child;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->child = NULL;
    }
};

*****************************************************************/
Node * mergeList(Node* list1, Node* list2) {
   Node *temp = new Node(-1);
   Node *res = temp;
   while(list1 && list2) {
    if(list1->data < list2->data) {
        temp->child = list1;
        list1 = list1->child;
        temp = temp->child;
        temp->next = NULL;
        
    } else {
        temp->child = list2;
        list2 = list2->child;
        temp = temp->child;
        temp->next = NULL;
        
    }
   } 
   if(list1) temp->child = list1;
   else temp->child = list2;
   return res->child;
}
Node* flattenLinkedList(Node* head) 
{   
    if(!head || !head->next) return head;
    
    head->next = flattenLinkedList(head->next);
    head = mergeList(head, head->next);

    return head;
}
