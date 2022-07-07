// CodeStudio link: https://bit.ly/33Bm8uX
// Leetcode link: https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/

void connectNodes(BinaryTreeNode< int > *root) {
    while(root) {
        BinaryTreeNode<int>* nextLvlRoot = NULL, currRoot = root, prevNode = NULL;
        while(currRoot) {
            if(currRoot->left) {
                if(!nextLvlRoot) {
                    nextLvlRoot = currRoot->left;
                } else {
                    prevNode->next = currRoot->left;
                }
                prevNode = currRoot>left;
            }
            if(currRoot->right) {
                if(!nextLvlRoot) {
                    nextLvlRoot = currRoot->right;
                } else {
                    prevNode->next = currRoot->right;
                }
                prevNode = currRoot>right;
            }
            currRoot = currRoot->next;
        }
        root = nextLvlRoot;
    }
}