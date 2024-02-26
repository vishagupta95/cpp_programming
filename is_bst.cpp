#include<iostream> 
using namespace std; 
  
/* A binary tree node has data,  
pointer to left child and  
a pointer to right child */
class node  
{  
    public: 
    int data;  
    node* left;  
    node* right;  
      
    /* Constructor that allocates  
    a new node with the given data 
    and NULL left and right pointers. */
    node(int data) 
    { 
        this->data = data; 
        this->left = NULL; 
        this->right = NULL; 
    } 
};
/*
1) Do In-Order Traversal of the given tree and store the result in a temp array.
3) Check if the temp array is sorted in ascending order, if it is, then the tree is BST.

Time Complexity: O(n)

We can avoid the use of Auxiliary Array. While doing In-Order traversal, we can keep track of previously visited node. If the value of the currently visited node is less than the previous value, then tree is not BST. Thanks to ygos for this space optimization.
*/



bool isBST(struct node* root) 
{ 
    static struct node *prev = NULL; 
      
    // traverse the tree in inorder fashion and keep track of prev node 
    if (root) 
    { 
        if (!isBST(root->left)) 
          return false; 
  
        // Allows only distinct valued nodes  
        if (prev != NULL && root->data <= prev->data) 
          return false; 
  
        prev = root; 
  
        return isBST(root->right); 
    } 
  
    return true; 
}  
  
int isBSTUtil(node* node, int min, int max);  
  
/* Returns true if the given  
tree is a binary search tree  
(efficient version). */
int isBST(node* node)  
{  
    return(isBSTUtil(node, INT_MIN, INT_MAX));  
}  
  
/* Returns true if the given 
tree is a BST and its values 
are >= min and <= max. */
int isBSTUtil(node* node, int min, int max)  
{  
    /* an empty tree is BST */
    if (node==NULL)  
        return 1;  
              
    /* false if this node violates 
    the min/max constraint */
    if (node->data < min || node->data > max)  
        return 0;  
      
    /* otherwise check the subtrees recursively,  
    tightening the min or max constraint */
    return
        isBSTUtil(node->left, min, node->data-1) && // Allow only distinct values  
        isBSTUtil(node->right, node->data+1, max); // Allow only distinct values  
}  
  
  
/* Driver code*/
int main()  
{  
    node *root = new node(4);  
    root->left = new node(2);  
    root->right = new node(5);  
    root->left->left = new node(1);  
    root->left->right = new node(3);  
      
    if(isBST(root))  
        cout<<"Is BST";  
    else
        cout<<"Not a BST";  
          
    return 0;  
}  
  
