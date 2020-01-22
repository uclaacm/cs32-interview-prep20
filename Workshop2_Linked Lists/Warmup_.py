# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteNode(self, node):
        """
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """
        #we make a check if the list has less than 2 nodes.
        if node == None or node.next == None:
            return
        
        """
        we set the current node's next's value.
        Then we make the current node point
        to the node's next's next node.
        """
        node.val = node.next.val
        node.next = node.next.next
        
        return