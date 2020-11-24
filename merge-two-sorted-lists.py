# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if l1 is None and l2 is None:
            return None
        elif l1 is None:
            return l2
        elif l2 is None:
            return l1
        
        i_dst = None
        i_src = None
​
        if l1.val < l2.val:
            i_dst = l1
            i_src = l2
        else:
            i_dst = l2
            i_src = l1
            
        ret = i_dst
​
        while i_src is not None:
            while i_dst.next is not None and i_dst.next.val < i_src.val:
                i_dst = i_dst.next
            
            tmp = i_src.next
            
            i_src.next = i_dst.next
            
            i_dst.next = i_src
            
            i_src = tmp
            
        return ret
