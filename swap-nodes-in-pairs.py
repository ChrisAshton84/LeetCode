# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if head is None:
            return head
​
        ret = head
        ptr = ret
        
        # Do initial swap that will affect ret
        if ret is not None and ret.next is not None:
            ret = ret.next
            ptr.next = ret.next
            ret.next = ptr
        
        while ptr.next is not None and ptr.next.next is not None:
            first = ptr.next
            second = ptr.next.next
            
            ptr.next = second
            first.next = second.next
            second.next = first
            
            ptr = first
            
        return ret
