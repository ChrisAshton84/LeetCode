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
​
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        if head is None:
            return head
        
        if k == 1:
            return head
        
        if k == 2:
            return self.swapPairs(head)
        
        # Left over code from implementation using recursion and no extra memory
        def swap2(node1prev: ListNode, node2prev: ListNode):
            if node1prev.next == node2prev:
                # want to go from:
                # node1prev->node1->node2->node2next
                # to:
                # node1prev->node2->node1->node2next
                node1 = node1prev.next
                node2 = node2prev.next
                node2next = node2.next
​
                node1.next = node2next
                node2.next = node1
                node1prev.next = node2
            else:
                # want to go from:
                # node1prev->node1->node1next, node2prev->node2->node2next
                # to:
                # node1prev->node2->node1next, node2prev->node1->node2next
                node1 = node1prev.next
                node1next = node1.next
​
                node2 = node2prev.next
                node2next = node2.next
​
                node2.next = node1next
                node1.next = node2next
​
                node1prev.next = node2
                node2prev.next = node1
        
        def nextN(node: ListNode, n: int) -> ListNode:
            ret = node
            
            while ret is not None and n > 0:
                ret = ret.next
            
            return ret
​
        nextPtrs = [None] * k
​
        # Set up a prev ptr which points to head to head - can use same algorithm for whole list now
        prevItr = ListNode(0, head)
        newHead = prevItr
​
        while prevItr.next is not None:
            itr = prevItr
​
            for i in range(k):
                nextPtrs[i] = itr.next
                itr = itr.next
​
                if itr is None and i < k: # If not a full list of k elements, return unchanged list
                    return newHead.next
                
            # We have an ordered array of pointers to list n0..nk-1 elements.
            # prevItr -> n0 -> n1 -> ... -> nk-1 -> nk
            # Need to update in reverse order such that
            # prevItr -> nk-1 -> ... -> n1 -> n0 -> nk
            nextPtrs[0].next = nextPtrs[k - 1].next
​
            for i in range(k - 1): # i: 0..k-2
                nextPtrs[i + 1].next = nextPtrs[i] # nextPtrs[1..k-1].next = nextPtrs[0..k-2]
            
            prevItr.next = nextPtrs[k - 1]
            
            prevItr = nextPtrs[0]
        
        return newHead.next
