# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        #define our result variable
        result = False
        

        #if the linked list is empty then return False because there is no cycle.
        if head == None:
            return result
        
        """We define two pointers."""
        ptr1 = head
        ptr2 = head
        
        """One pointer moves from current node to next node. The other moves from 
        current node to the next node's next node.
        """
        
        ptr1 = ptr1.next
        if ptr1 != None:
            ptr1 = ptr1.next
        ptr2 = ptr2.next

        #make sure neither run to the end.
        while ptr1 != None and ptr2 != None:
            if ptr1 == ptr2:                #we have a cycle.
                result = True
                break
            else:
                ptr1 = ptr1.next            #we have not yet discovered the linked list.
                if ptr1 != None:
                    ptr1 = ptr1.next
                ptr2 = ptr2.next
        
        return result