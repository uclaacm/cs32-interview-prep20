# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        
        #if the list has no nodes or one node it is already reversed
        if head == None or head.next == None:
            return head
        
        #we keep track of two nodes one that points to a given node while the other node
        prev = None
        curr = head
        
        #iterate through till the end of the list
        while curr != None:
            temp = curr.next    #keep track of the current's node next node.
            curr.next = prev    #set the current node's next to the prev node
            prev = curr         #update the prev node to curr because it will be a "previous" node in the next iteration.
            curr = temp         #curr is set to the next node because it will be a "current" node in the next iteration.
        
        #prev will be the new head.
        return prev