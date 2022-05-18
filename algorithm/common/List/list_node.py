from typing import List

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
    
    # Array -> Listed-List
    @classmethod
    def array_to_list(cls, data: List):
        if len(data) == 0:
            return None
        head = cls()
        p = cls()
        p.next = head
        for _, x in enumerate(data):
            p = p.next
            p.val = x
            p.next = cls()
        p.next = None
        return head
    
    # Listed-List -> Array
    @classmethod
    def list_to_array(cls, head):
        ans = []
        while head != None:
            ans.append(head.val)
            head = head.next
        return ans

if __name__ == "__main__":
    pass