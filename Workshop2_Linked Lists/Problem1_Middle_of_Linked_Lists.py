# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        #if the linked list is empty then return False because there is no cycle.
        if head == None:
            return None
        
        """We define two pointers. One that moves faster than the other."""
        ptr1 = head
        ptr2 = head
        
        """One pointer moves from current node to next node. The other moves from 
        current node to the next node's next node.
        """
        
        #make sure neither run to the end.
        while ptr1 != None and ptr2 != None:
            ptr1 = ptr1.next
            if ptr1 != None:
                ptr1 = ptr1.next
            else:                   #ptr1 has reached the end of the list which means ptr2 is in the middle.
                break                
            ptr2 = ptr2.next
        
        return ptr2