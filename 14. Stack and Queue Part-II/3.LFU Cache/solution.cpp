// CodeStudio link: https://bit.ly/3noxuK0
// Leetcode link: https://leetcode.com/problems/lfu-cache/
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int key, val, cnt ;
        node* next, *prev;
        node(int _key,int _val) {
            key = _key;
            val = _val;
            cnt = 1;
        }    
    
};
class LFUCache
{
    int capacity;
    map<int, node*> countMap;
    unordered_map<int, node*> nodeMap;
public:
    void clearCountMap(int cnt) {
        node* list = countMap[cnt];
        if(list->next->next == list) {
            countMap.erase(cnt);
        }
    }
    void addNode(node* head, node* newNode)
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
    LFUCache(int _capacity)
    {
        // Write your code here.
        capacity = _capacity;
    }

    int get(int key)
    {
        // Write your code here.
        if(nodeMap.find(key) != nodeMap.end()) {
            node* key_node = nodeMap[key];
            int val = key_node->val, cnt = key_node->cnt;
            nodeMap.erase(key);
            removeNode(key_node);
            clearCountMap(cnt);
            if(countMap.find(cnt+1) == countMap.end()) {
                node* head = new node(-1,-1);
                node* tail = new node(-1,-1);
                head->next = tail;
                tail->prev = head;
                head->prev = tail;
                tail->next = head;
                countMap[cnt+1] = head;
            } 
            addNode(countMap[cnt+1], new node(key,val));
            nodeMap[key] = countMap[cnt+1]->next;
            nodeMap[key]->cnt = cnt+1;
            return val;
        }
        return -1;
    }
    
    void put(int key, int value)
    {   int cnt = 0;
        if(nodeMap.find(key) != nodeMap.end()) {
            node* key_node = nodeMap[key];
            cnt = key_node->cnt;
            nodeMap.erase(key);
            removeNode(key_node);
            clearCountMap(cnt);
            
        } 
            if(capacity == nodeMap.size()) {
                node* least_list = countMap.begin()->second;
                nodeMap.erase(least_list->prev->prev->val);
                removeNode(least_list->prev->prev);
                clearCountMap(countMap.begin()->first);
            }
            if(countMap.find(cnt+1) == countMap.end()) {
                node* head = new node(-1,-1);
                node* tail = new node(-1,-1);
                head->next = tail;
                tail->prev = head;
                head->prev = tail;
                tail->next = head;
                countMap[cnt+1] = head;
            } 
            addNode(countMap[cnt+1], new node(key,value));
            nodeMap[key] = countMap[cnt+1]->next;
            nodeMap[key]->cnt = cnt+1;
    }
};
