from util import Queue 

# -----------------------------------------
class BinaryTree: 

    def __init__(self): 
        self.root = None 

    def insertKey(self, ele): 
        if self.root is None: 
            self.root = BinaryTreeNode()
            self.root.data = ele 
        else: 
            queue = Queue()
            queue.enQueue(self.root)
            while not queue.isEmpty(): 
                node = queue.deQueue()
                if node.left is None: 
                    node.left = BinaryTreeNode()
                    node.left.data = ele 
                    break 
                else: 
                    queue.enQueue(node.left)

                if node.right is None: 
                    node.right = BinaryTreeNode()
                    node.right.data = ele 
                    break 
                else: 
                    queue.enQueue(node.right)

    def inorderTraversal(self): 
        return self._inorderTraversal(self.root) 

    def _inorderTraversal(self, node): 
        if node is not None: 
            self._inorderTraversal(node.left)
            print(node.data, end = ", ")
            self._inorderTraversal(node.right)

    def height(self): 
        if self.root is None: 
            return -1 
        else: 
            return self._height(self.root)

    def _height(self, node): 
        if node is None: 
            return 0 
        else: 
            lh = self._height(node.left)
            rh = self._height(node.right)
            return max(lh, rh) + 1; 


    def number_of_node(self): 
        if self.root is None: 
            return 0 
        else: 
            return self._number_of_nodes(self.root)

    def _number_of_nodes(self, node): 
        if node is None: 
            return 0 
        else: 
            return self._number_of_nodes(node.left) + self._number_of_nodes(self.right) + 1 

    
    def levelOrderTraversal(self): 
        queue = Queue()
        queue.enQueue(self.root)
        while not queue.isEmpty(): 
            node = queue.deQueue()
            if node.left is not None: 
                queue.enQueue(node.left)
            if node.right is not None: 
                queue.enQueue(node.right)
            print(node.data, end = ", ")
        print()

# -----------------------------------------
class BinaryTreeNode: 

    def __init__(self): 
        self.data = None 
        self.left = None 
        self.right = None 

    
# -------------------------------------------- 

if __name__ == '__main__': 
    pass 
