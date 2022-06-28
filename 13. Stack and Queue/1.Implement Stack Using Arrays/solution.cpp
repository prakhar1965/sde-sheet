// codestudio link: https://www.codingninjas.com/codestudio/problems/stack-implementation-using-array_3210209?peekList=striver-sde-sheet-problems
// Stack class.
class Stack {
    int *arr, peek, capacity;
public:
    
    Stack(int _capacity) {
        // Write your code here.
        arr = new int[_capacity];
        peek = -1;
        capacity = _capacity;
    }

    void push(int num) {
        // Write your code here.
        if(peek >= (capacity-1)) return;
        arr[++peek] = num;
    }

    int pop() {
        // Write your code here.
        if(peek < 0) return -1;
        int popEle = arr[peek--];
        return popEle;
    }
    
    int top() {
        // Write your code here.
        return peek < 0 ? -1 : arr[peek];
    }
    
    int isEmpty() {
        // Write your code here.
        return peek == -1;
    }
    
    int isFull() {
        // Write your code here.
        return peek >= (capacity-1);
    }
    
};