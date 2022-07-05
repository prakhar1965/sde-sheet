// Solution link: https://takeuforward.org/data-structure/check-for-children-sum-property-in-a-binary-tree/
// CodeStudio link: https://bit.ly/33yExIQ
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void changeTree(BinaryTreeNode < int > * root) {
    if(!root) return;
    if(!root->left && !root->right) return;
    
    int x = 0;
    if(root->left) x+= root->left->data;
    if(root->right) x+= root->right->data;
    if(root->data > x) 
    {
        if(root->left) root->left->data = root->data;
        else if(root->right) root->right->data = root->data;
    }
    
    changeTree(root->left);
    changeTree(root->right);

    int y = 0;
    if(root->left) y+= root->left->data;
    if(root->right) y+= root->right->data;
    root->data = y;
}  
