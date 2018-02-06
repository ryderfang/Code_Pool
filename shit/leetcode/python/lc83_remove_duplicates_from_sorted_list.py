# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        p = head
        q = p.next if p != None else None
        while p != None:
            if q != None and q.val == p.val:
                q = q.next
            else:
                p.next = q
                p = q
                q = q.next if q != None else None
        return head