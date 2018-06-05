# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head == None:
            return None
        p = head
        q = p.next
        while q != None:
            t = q.next
            q.next = p
            p = q
            q = t
        head.next = None
        return p
