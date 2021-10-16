// C++ program to print right view of Binary Tree
#include <bits/stdc++.h>
using namespace std;
 
// A utility function for creating a node in a tree
struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
// Recursive function to print
// right view of a binary tree.
 
void traversal(TreeNode* A, vector<int> &v , int d)
{
    if(A==NULL)
    {
        return;
    }
 
    if(v.size()<d)
    {
        v.push_back(A->val);
    }
 
    traversal(A->right,v,d+1);
    traversal(A->left,v,d+1);
}
 
vector<int> rightview(TreeNode* A)
{
    vector<int> v;
 
    traversal(A,v,1);
 
    return v;
}
 
// Driver Code
int main()
{
	TreeNode* root = TreeNode(15);
	root->left = TreeNode(1);
	root->right = TreeNode(9);
	root->left->left = TreeNode(7);
	root->left->right = TreeNode(6);
	root->right->right = TreeNode(20);
	root->right->left = TreeNode(3);
	root->right->right->left = TreeNode(5);
 
	rightview(root);
 
	return 0;
}
