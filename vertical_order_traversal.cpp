/*

Given a binary tree, perform vertical traversal of it. In vertical traversal, we print nodes of a binary tree in vertical 
order by assuming that the left and right child of a node makes 45 degree angle with the parent. 
This problem can be easily solved with the help of Hashing and pre order traversal.

The idea is to create an empty map where each key represents the relative horizontal distance of a node from the root node and i
value in the map maintains all nodes present at same horizontal distance. Then we do a of the tree and we update the map. For each 
node, we recur for its left subtree by decreasing horizontal distance by 1 and recur for right subtree by increasing 
horizontal distance by 1.

                                   1
                          2               3
                                   5          6
                                    
                            7         8


For above binary tree, the final values in the map will be

-1 -> [2, 7]
0 -> [1, 5]
1 -> [3, 8]
2 -> [6]

*/
#include <iostream>
#include <map>
using namespace std;
 
// Data structure to store a binary tree node
struct Node
{
    int data;
    Node *left, *right;
 
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};
 
// Recursive function to perform preorder traversal on the tree and fill the map.
// Here, the node has `dist` horizontal distance from the tree's root
void printVertical(Node* node, int dist, auto &map)
{
    // base case: empty tree
    if (node == nullptr) {
        return;
    }
 
    // insert nodes present at a current horizontal distance into the map
    map.insert(make_pair(dist, node->data));
 
    // recur for the left subtree by decreasing horizontal distance by 1
    printVertical(node->left, dist - 1, map);
 
    // recur for the right subtree by increasing horizontal distance by 1
    printVertical(node->right, dist + 1, map);
}
 
// Function to perform vertical traversal on a given binary tree
void printVertical(Node* root)
{
    // create an empty map where
    // key —> relative horizontal distance of the node from the root node, and
    // value —> nodes present at the same horizontal distance
    multimap<int, int> map;
 
    /* We can also use `map<int, vector<int>>` instead of `multimap<int, int>` */
 
    // perform preorder traversal on the tree and fill the map
    printVertical(root, 0, map);
 
    // traverse the map and print the vertical nodes
    int temp = 0;
    for (auto it = map.begin(); it != map.end(); it++)
    {
        if (temp != it->first)
        {
            cout << endl;
            temp = it->first;
        }
        cout << it->second << " ";
    }
}
 
int main()
{
    /* Construct the following tree
            1
          /   \
         /     \
        2       3
              /   \
             /     \
            5       6
          /   \
         /     \
        7       8
              /   \
             /     \
            9      10
    */
 
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);
    root->right->left->right->left = new Node(9);
    root->right->left->right->right = new Node(10);
 
    printVertical(root);
 
    return 0;
}

