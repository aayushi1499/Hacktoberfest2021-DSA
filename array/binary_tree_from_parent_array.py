# A class to store a binary tree node
class Node:
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right
 
 
# Function to perform inorder traversal on the tree
def inorder(root):
 
    if root is None:
        return
 
    inorder(root.left)
    print(root.data, end=' ')
    inorder(root.right)
 
 
# Function to build a binary tree from the given parent list
def createTree(parent):
 
    # create an empty dictionary
    dict = {}
 
    # create `n` new tree nodes, each having a value from 0 to `n-1`,
    # and store them in a dictionary
    for i in range(len(parent)):
        dict[i] = Node(i)
 
    # represents the root node of a binary tree
    root = None
 
    # traverse the parent list and build the tree
    for i, e in enumerate(parent):
 
        # if the parent is -1, set the root to the current node having the
        # value `i` (stored in `dict[i]`)
        if e == -1:
            root = dict[i]
        else:
            # get the parent for the current node
            ptr = dict[e]
 
            # if the parent's left child is filled, map the node to its right child
            if ptr.left:
                ptr.right = dict[i]
            # if the parent's left child is empty, map the node to it
            else:
                ptr.left = dict[i]
 
    # return root of the constructed tree
    return root
 
 
if __name__ == '__main__':
 
    parent = [-1, 0, 0, 1, 2, 2, 4, 4]
 
    root = createTree(parent)
    inorder(root)

# Ex - input: -1, 0, 0, 1, 2, 2, 4, 4
#      output: 3 1 0 6 4 7 2 5
