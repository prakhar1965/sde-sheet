// Solution link: https://takeuforward.org/data-structure/implement-queue-using-array/
// CodeStudio link: https://bit.ly/3KbIjIW
#include<bits/stdc++.h>
using namespace std;
class Queue {
   int *arr;
   int start, rear, currSize, maxSize = 1;

    int *increaseSizeOfQueue(int *arr) {
        maxSize = maxSize*2;
        int *newArray = new int[maxSize];
        int curr = 0;
        
        for(int i=start; i != rear; i = (i+1) % currSize) {
            newArray[curr++] = arr[i];    
        } 
        newArray[curr] = arr[rear];
        start = 0;
        rear = currSize-1;
        return newArray;
    }
public:
    Queue() {
        arr = new int[maxSize];
        start = -1;
        rear = -1;
        currSize = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/
    bool isEmpty() {
    
        return currSize == 0; 
    }

    void enqueue(int data) {
    
        if(currSize == maxSize) {
            arr = increaseSizeOfQueue(arr);
        }
        if(rear == -1) {
            start = 0;
            rear = 0;
        } else 
            rear = (rear+1) % maxSize;
        arr[rear] = data;
        currSize++;
    }

    int dequeue() {
        if(currSize == 0) return -1;
        int startElement = arr[start];
        
        if(currSize == 1) {
            rear = -1;
            start = -1;
        } else 
            start = (start+1) % maxSize;
        currSize--;
        return startElement;
    }

    int front() {

        return currSize == 0 ? -1 : arr[start];
    }
};