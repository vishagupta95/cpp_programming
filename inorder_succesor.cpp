/* 
 * inorder successor is the node with the least value in its right subtree, i.e., its rightsubtree is leftmost child. 
If the right subtree of the node doesnt exist, then the inorder successor isone of its ancestors. To find which ancestors are the successor, 
we can move up the tree towardsthe root until we encounter a node that is left child of its parent. If any such node is found, 
then inorder successor is its parent; otherwise, inorder successor does not exist for the node.
 Construct the following tree
               15
             /    \
            /      \
           10       20
          / \      /  \
         /   \    /    \
        8    12  16    25
  
The inorder successor of 8 is 10
The inorder successor of 12 is 15
the inorder successor of 25 does not exist.


*/
#include <iostream>
using namespace std;
 
// Data structure to store a BST node
struct Node
{
    int data;
    Node *left, *right;
};
 
// Function to create a new binary tree node having a given key
Node* newNode(int key)
{
    Node* node = new Node;
    node->data = key;
    node->left = node->right = nullptr;
 
    return node;
}
 
// Recursive function to insert a key into a BST
Node* insert(Node* root, int key)
{
    // if the root is null, create a new node and return it
    if (root == nullptr) {
        return newNode(key);
    }
 
    // if the given key is less than the root node, recur for the left subtree
    if (key < root->data) {
        root->left = insert(root->left, key);
    }
 
    // if the given key is more than the root node, recur for the right subtree
    else {
        root->right = insert(root->right, key);
    }
 
    return root;
}
 
// Helper function to find minimum value node in a given BST
Node* findMinimum(Node* root)
{
    while (root->left) {
        root = root->left;
    }
 
    return root;
}
 
// Iterative function to find an inorder successor for the given key in a BST
Node* findSuccessor(Node* root, int key)
{
    Node* succ = nullptr;
 
    while (1)
    {
        // if the given key is less than the root node, visit the left subtree
        if (key < root->data)
        {
            // update successor to the current node before visiting left subtree
            succ = root;
            root = root->left;
        }
 
        // if the given key is more than the root node, visit the right subtree
        else if (key > root->data) {
            root = root->right;
        }
 
        // if a node with the desired value is found, the successor is the minimum
        // value node in its right subtree (if any)
        else {
            if (root->right) {
                succ = findMinimum(root->right);
            }
            break;
        }
 
        // if the key doesn't exist in the binary tree
        if (!root) {
            return nullptr;
        }
    }
 
    // return successor, if any
    return succ;
}
 
int main()
{
    int keys[] = { 15, 10, 20, 8, 12, 16, 25 };
 
    /* Construct the following tree
               15
             /    \
            /      \
           10       20
          / \      /  \
         /   \    /    \
        8    12  16    25
    */
 
    Node* root = nullptr;
    for (int key: keys) {
        root = insert(root, key);
    }
 
    // find inorder successor for each key
    for (int key: keys)
    {
        Node* prec = findSuccessor(root, key);
 
        if (prec != nullptr) {
            cout << "The successor of node " << key << " is " << prec->data;
        }
        else {
            cout << "The successor doesn't exist for " << key;
        }
 
        cout << endl;
    }
 
    return 0;
}


