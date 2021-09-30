from BinaryTree import BinaryTree, BinaryTreeNode  


# -----------------------------------------------------------------

class BinarySearchTree(BinaryTree): 

    def __init__(self): 
        super().__init__()
    
    def insertKey(self, ele):
        if self.root is None: 
            self.root = BinaryTreeNode()
            self.root.data = ele 
        else:
            return self._insertKey(self.root, ele)

    def _insertKey(self, node, ele): 
        if node.data <= ele: 
            if node.right is None: 
                node.right = BinaryTreeNode()
                node.right.data = ele 
            else: 
                return self._insertKey(node.right, ele)
        else: 
            if node.left is None: 
                node.left = BinaryTreeNode()
                node.left.data = ele 
            else: 
                return self._insertKey(node.left, ele)

 



# --------------------------------------------------------------------
if __name__ == '__main__': 
    bst = BinarySearchTree()
    bst.insertKey(11)
    bst.insertKey(10)
    bst.insertKey(12)
    bst.inorderTraversal()
    
