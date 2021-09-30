# filename : TreeProblem.py 

from BinarySearchTree import BinarySearchTree 
from BinaryTree import BinaryTree, BinaryTreeNode 
from util import Queue 
import random 

# ---------------------- problem : 1 ------------------------------------------


""" 
    * Given Sorted Array with unique integers make a Binary Serach Tree out of it with minimal Height. 
"""
binaryTree = BinarySearchTree()
def minimal_height_binary_serach_tree_from_sorted_array(arr, binaryTree, start, end):
    # recursive approch. 
    if start > end: 
        return None 
    else: 
        mid = int((start + end)/2)
        print(f"mid : {mid} start : {start} end : {end}")
        binaryTree.insertKey(arr[mid])
        minimal_height_binary_serach_tree_from_sorted_array(arr, binaryTree, start, mid - 1)
        minimal_height_binary_serach_tree_from_sorted_array(arr, binaryTree, mid + 1, end)
 


#--------------------------------------------------------------------------------------------------------------------



# --------------------- problem : 2 -------------------------------------------- 
"""
    * Given an BinaryTree make a Linked of list which contain nodes of each level 
    * if there is L level we need L linked List them. 
"""

def get_node_of_each_depth_in_linked_list(binaryTree  : BinaryTree): 
    
    aux_queue = Queue()
    aux_queue.enQueue(binaryTree.root) # insert root node in Queue First. 
    lst = []
    lst.append([])
    aux_queue.enQueue(None) # Here None is my delimitor. 
    while not aux_queue.isEmpty(): 
        node = aux_queue.deQueue()
        if node is None: 
            if not aux_queue.isEmpty():        
                aux_queue.enQueue(None)
                lst.append([])
            continue 
        lst[len(lst) - 1].append(node.data)
        if node.left is not None: 
            aux_queue.enQueue(node.left)
        if node.right is not None: 
            aux_queue.enQueue(node.right)
    return lst 

# -------------------------------------------------------------------
# get leftview of BinaryTree 


def leftView(node : BinaryTreeNode): 
    if node is not None: 
        print(node.data, end = ", ")
        if node.left is not None: 
            leftView(node.left)
        else: 
            leftView(node.right)
    


# -----------------------Testing------------------------------------------------
if __name__ == '__main__':
    binaryTree = BinaryTree()
    for i in range(16): 
        binaryTree.insertKey(random.randint(1, 100))
    
    lst = get_node_of_each_depth_in_linked_list(binaryTree)
    print(lst)
    binaryTree.levelOrderTraversal()

    print("-----------------")
    leftView(binaryTree.root)
