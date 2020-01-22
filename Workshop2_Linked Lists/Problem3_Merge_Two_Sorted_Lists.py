# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        dummy = ListNode(0) #create a dummy node to point to the head of the list.
        cur = dummy
        while l1 != None and l2 != None:    #while we have not run to the end of either list.
            if l1.val < l2.val: #l1's node comes before l2's node
                cur.next = l1
                l1 = l1.next
            else:               #l2's node comes before l1's node
                cur.next = l2
                l2 = l2.next
            cur = cur.next
        cur.next = l1 or l2     # the list that is not yet reached the end is appended to the end.

        return dummy.next       # we return dummy.next because it is the first node in the combined list.