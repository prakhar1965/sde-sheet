// Solution link: https://takeuforward.org/data-structure/implement-lru-cache/
// CodeStudio link: https://bit.ly/3K7Cs7I
// Leetcode link: https://leetcode.com/problems/lru-cache/
#include<bits/stdc++.h>
using namespace std;

class node {
    public:
        int value;
        int key;
        node *next;
        node* prev;
        node(int _key, int val) {
            value = val;
            key = _key;
            next = NULL;
        }
};
class LRUCache
{
    node* head;
    node* tail;
    unordered_map<int, node*> hashMap;
    int capacity;
    void addNodeAtEnd(node* newNode)
    {
        node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }
    void removeNode(node* key_node) 
    {
        node* remove_next = key_node->next;
        node* remove_prev = key_node->prev;
        remove_next ->prev = remove_prev;
        remove_prev-> next = remove_next;    
    }
public:
    LRUCache(int _capacity)
    {
        // Write your code here
        head = new node(-1,-1);
        tail = new node(-1,-1);
        head->next = tail;
        tail->prev = head;
        capacity = _capacity;
    }

    int get(int key)
    {
        // Write your code here
        if(hashMap.find(key) != hashMap.end()) {
            node* key_node = hashMap[key];
            int val = key_node->value;
            hashMap.erase(key);
            removeNode(key_node);
            addNodeAtEnd(new node(key, val));
            hashMap[key] = head->next;
            return val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        // Write your code here
       
        if(hashMap.find(key) != hashMap.end()) {
            node* key_node = hashMap[key];
            hashMap.erase(key);
            removeNode(key_node);
        }
         if(hashMap.size() == capacity) {
            hashMap.erase(tail->prev->key);
            removeNode(tail->prev);
        }
        addNodeAtEnd(new node(key,value));
        hashMap[key] = head->next;
    }
};
