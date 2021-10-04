#include <iostream>
using namespace std;
 
// Data structure to store a BST node
struct Node
{
    int data;
    Node *left, *right;
};
 
// Function to create a new BST node having a given key
Node* newNode(int key)
{
    Node* node = new Node;
    node->data = key;
    node->left = node->right = nullptr;
 
    return node;
}
 
// Function to perform inorder traversal on the tree
void inorder(Node* root)
{
    if (root == nullptr) {
        return;
    }
 
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
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
 
// Iterative function to search a given key in a BST
bool search(Node* root, int key)
{
    // traverse the tree and search for the key
    while (root)
    {
        // if the given key is less than the current node, go to the left
        // subtree; otherwise, go to the right subtree
 
        if (key < root->data) {
            root = root->left;
        }
        else if (key > root->data) {
            root = root->right;
        }
        // if the key is found, return true
        else {
            return true;
        }
    }
 
    // we reach here if the key is not present in the BST
    return false;
}
 
// Recursive function to find the lowest common ancestor of given nodes
// `x` and `y`, where both `x` and `y` are present in a BST
Node *LCARecursive(Node* root, int x, int y)
{
    // base case: empty tree
    if (root == nullptr) {
        return nullptr;
    }
 
    // if both `x` and `y` is smaller than the root, LCA exists in the left subtree
    if (root->data > max(x, y)) {
        return LCARecursive(root->left, x, y);
    }
 
    // if both `x` and `y` are greater than the root, LCA exists in the right subtree
    else if (root->data < min(x, y)) {
        return LCARecursive(root->right, x, y);
    }
 
    // if one key is greater (or equal) than the root and one key is smaller
    // (or equal) than the root, then the current node is LCA
    return root;
}
 
// Print lowest common ancestor of two nodes in a BST
void LCA(Node* root, int x, int y)
{
    // return if the tree is empty, or `x` or `y` is not present in the tree
    if (root == nullptr || !search(root, x) || !search(root, y)) {
        return;
    }
 
    // `lca` stores the lowest common ancestor of `x` and `y`
    Node* lca = LCARecursive(root, x, y);
 
    // if the lowest common ancestor exists, print it
    if (lca != nullptr) {
        cout << "LCA is " << lca->data << endl;
    }
    else {
        cout << "LCA does not exist\n";
    }
}
 
int main()
{
    int keys[] = { 15, 21, 18, 12, 32, 16, 24 };
 
    Node* root = nullptr;
    for (int key: keys) {
        root = insert(root, key);
    }
 
    LCA(root, 21, 12);
 
    return 0;
}
