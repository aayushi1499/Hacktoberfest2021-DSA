# filename : LInkedListNode.py 
import random 

# class Name : LinkedListNode. 
class LinkedListNode: 

    def __init__(self): 
        self.data = None # data of the node. 
        self.next = None  # next pointer of Node. 

        

# class Name : LinkedList 
class LinkedList: 
    def __init__(self): 
        self.head = None 

    def insertKey(self, data): 
        if self.head is None: 
            self.head = LinkedListNode() 
            self.head.data = data 
        else: 
            tempNode = self.head 
            while tempNode.next is not None: 
                tempNode = tempNode.next 
            tempNode.next = LinkedListNode()
            tempNode.next.data = data  

    def printList(self): 
        if self.head is None: 
            print("List is empty")
        else: 
            tempNode = self.head 
            while tempNode is not None: 
                print(tempNode.data, end = ", ")
                tempNode = tempNode.next  
            print()


# Testing are for LinkedListNode. 
if __name__ == "__main__": # testing mode.  
    linkedlist = LinkedList() # linked list. 
    for i in range(0, 20): 
        linkedlist.insertKey(random.randint(1, 100)) # insert the random number form 1 to 100 in the linked list. 
    linkedlist.printList() # print linked list. 
