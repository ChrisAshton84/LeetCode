# """
# This is MountainArray's API interface.
# You should not implement it, or speculate about its implementation
# """
#class MountainArray:
#    def get(self, index: int) -> int:
#    def length(self) -> int:
​
class Solution:
    def findInMountainArray(self, target: int, mountain_arr: 'MountainArray') -> int:
        # Basically a binary search over a sorted array, except that there is a pivot
        # at some point where the direction switches.  Need to test the slope to determine
        # whether that has happened.  Pivot is guaranteed not to be head or tail.
        
        # Since we are looking for the minimum value, try to find it on lhs before trying rhs
        
        # Stash a local copy of the length in case it is expensive
        length = mountain_arr.length()
        debug = True
        ret = -1 # Return value
​
        # It might help to not have to deal with either end element directly, so do a test for those explicitly
        lhs = mountain_arr.get(0)
        not_on_left = False
        not_on_right = False
        
        if lhs == target:
            return 0
        elif lhs > target:
            not_on_left = True
        
        rhs = mountain_arr.get(length - 1)
​
        if rhs == target:
            if not_on_left == True:
                return length - 1
        elif rhs > target:
            not_on_right = True
            
        # At this point we know whether it can exist on lhs or rhs.  Find that pivot point. (Can't be ends)
        left = 1
        right = length - 2
        pivot = -1
        
        # Binary search - looking for pivot which cannot be lhs or rhs
        while left <= right:
            mid = left + ((right - left) // 2)
​
            if debug: print("length:", length, "left:", left, "mid:", mid, "right", right)
​
            val = mountain_arr.get(mid)
            to_right = mountain_arr.get(mid + 1)
            to_left  = mountain_arr.get(mid - 1)
            
            # Assume looking up the entry might be expensive, so cache lowest matching index found
            if to_left == target:
                if ret == -1 or mid - 1 < ret:
                    ret = mid - 1
​
            if val == target:
                if ret == -1 or mid < ret:
                    ret = mid
​
            if to_right == target:
                if ret == -1 or mid + 1 < ret:
                    ret = mid + 1
​
            if val < to_right: # a[i] < a[i + 1] so we need to go right
                left = mid + 1
            elif to_left > val: # a[i - 1] > a[i] so we need to go left
                right = mid - 1
            else: # Found the pivot!
                pivot = mid
                break
                
        if ret != -1 and ret <= pivot: # If previously discovered a match that is guaranteed minimum, return it
            return ret
        
        # Haven't yet found match - if possible, check lhs
        if not_on_left == False:
            left = 0
            right = pivot
            
            while left <= right:
                mid = left + (right - left) // 2
                
                val = mountain_arr.get(mid)
                
                if val == target: # Now we know we're on the left, so a match is guaranteed to be minimum
                    return mid
                
                if val < target: # On left - sorted in forward order - need to go right
                    left = mid + 1
                else:
                    right = mid - 1
​
        # Similarly for right hand side
        if not_on_right == False:
            left = pivot + 1
            right = length - 1
            
            while left <= right:
                mid = left + (right -left) // 2
                
                val = mountain_arr.get(mid)
                
                if val == target: # As last choice, return this value from rhs
                    return mid
                
                if val < target: # On rhs, values sorted in reverse order - need to go left
                    right = mid - 1
                else:
                    left = mid + 1
                    
        return ret
