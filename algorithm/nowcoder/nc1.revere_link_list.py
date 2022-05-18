class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None
#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 
# @param head ListNode类 
# @return ListNode类
#
class Solution:
    def ReverseList(self , head: ListNode) -> ListNode:
        # write code here
        p = head
        q = None
        if p != None:
            q = p.next
            p.next = None
        while q != None:
            t = q.next
            q.next = p
            p = q
            q = t
        return p