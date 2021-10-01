#Remove duplicates in a linked list:

class Solution:
    def delete(self,key):
        a = key.next
        key.next = a.next
        
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        cur = head 
        while head and head.next:
            if head.val == head.next.val:
                self.delete(head)
            else:
                head = head.next
        return cur            
