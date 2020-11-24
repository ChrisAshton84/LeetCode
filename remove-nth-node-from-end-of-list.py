# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        if head.next is None:
            return None
​
        # Run a counter N ahead
        nth_ahead = head
        #print("head: ", head, ", nth_ahead: ", nth_ahead)
        
        idx = 0
        while(idx < n):
            idx += 1
            nth_ahead = nth_ahead.next
            #print("  idx: ", idx, "head: ", head, ", nth_ahead: ", nth_ahead)
​
        if nth_ahead is None:
            return head.next            
​
        prev = head
        #print("prev: ", prev)
        
        # Now run counter until at end
        # This will mean prev will be one behind the 'nth' from end elem
        while nth_ahead.next is not None:
            nth_ahead = nth_ahead.next
            prev = prev.next
            #print("   nth_ahead: ", nth_ahead, ", prev: ", prev)
            
        prev.next = prev.next.next
        
        return head
