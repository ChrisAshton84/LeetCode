class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        ret = [] # Return a list
​
        n_nums = len(nums)
        
        if (n_nums < 3): # Ensure there are enough elements
            return ret
​
        nums.sort() # Order nums O(n*log(n))
        
        if (nums[0] > 0): # If all numbers are positive,
            return ret    # cannot sum to 0
​
        if (nums[n_nums - 1] < 0): # If all numbers are negative,
            return ret             # cannot sum to 0
​
        for i in range(n_nums - 2): # Check all neg values for a complementary pair in remaining numbers
            cur_num = nums[i]       # O(n) * (O(n) from twoSum) = O(n*n)
            complement = -cur_num
​
            if ((cur_num <= 0) and ((i == 0) or (cur_num != nums[i - 1]))):
                matches = self.twoSum(nums[i + 1:], complement) # O(n)
                
                for match in matches:
                    ret.append(match)
​
        return ret
​
    def twoSum(self, nums: List[int], target: int):
        ret = [] # Return a list
        
        low, high = 0, len(nums) - 1
        
        while (low < high): # Look over all numbers, always incrementing at least one index O(n)
            sum = nums[low] + nums[high]
            
            if (sum < target): # Grow sum if it's too small
                low += 1
            elif (sum > target): # Shrink sum if it's too large
                high -= 1
            else:
                ret.append([-target, nums[low], nums[high]]) # Record sum components
                
                low += 1
                high -= 1 # Skip these used elements
                
                while ((low < high) and (nums[low] == nums[low -1])):
                    low += 1 # Skip matching elements
​
        return ret
