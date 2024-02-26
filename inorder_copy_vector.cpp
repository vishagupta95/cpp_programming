// C++ program to demonstrate how vectors
// can be passed by reference.
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
/*
 *  a tree has n nodes, then each node is visited only once in inorder traversal and hence the complexity is O(n).
 */

/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct Node {
	int data;
	struct Node *left, *right;
};

// Utility function to create a new tree node
Node* newNode(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

/* Given a binary tree, print its nodes in inorder*/
void printInorder(struct Node* node ,vector<int>& vect)
{
	if (node == NULL)
		return;

	/* first recur on left child */
	printInorder(node->left ,vect);

	/* then print the data of node */
        vect.push_back(node->data);

	/* now recur on right child */
	printInorder(node->right ,vect);
}

/* Driver code*/
int main()
{
	vector<int> vect;
	struct Node* root = newNode(6);
	root->left = newNode(4);
	root->right = newNode(8);
	root->left->left = newNode(1);
	root->left->right = newNode(5);
	// Function call
	cout << "\nInorder traversal of binary tree is \n";
	printInorder(root ,vect);
	
        for (int i = 0; i < vect.size(); i++)
		cout << vect[i] << " ";


	return 0;
}

