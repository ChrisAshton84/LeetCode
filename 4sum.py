class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        #print("nums: ", nums, ", target: ", target)
        
        res = []
        
        if len(nums) < 4:
            return res
        
        if target >= 0 and nums[0] > target:
            return res # Guaranteed too big
        
        if target >= 0 and nums[-1] * 4 < target:
            return res # Guaranteed too small
        
        if target < 0 and nums[-1] < target:
            return res # Guaranteed too small
        
        if target < 0 and nums[0] * 4 > target:
            return res # Guaranteed too big
        
        for idx in range(len(nums) - 3):
            idx_val = nums[idx]
            idx_remaining = target - idx_val
            #print("  idx_val: ", idx_val, " remaining: ", idx_remaining)
​
            if (idx == 0) or (nums[idx - 1] != idx_val):
                for jdx in range(idx + 1, len(nums) - 2):
                    jdx_val = nums[jdx]
                    jdx_remaining = target - idx_val - jdx_val
                    #print("    jdx_val: ", jdx_val, " remaining: ", jdx_remaining)
​
                    low, high = jdx + 1, len(nums) - 1
​
                    while (low < high):
                        inner_sum = nums[low] + nums[high]
​
                        if (inner_sum < jdx_remaining):
                            low += 1
                        elif (inner_sum > jdx_remaining):
                            high -= 1
                        else:
                            if not [idx_val, jdx_val, nums[low], nums[high]] in res:
                                res.append([idx_val, jdx_val, nums[low], nums[high]])
                            
                            low += 1 
                            
                            while (low < high) and (nums[low - 1] == nums[low]):
                                low += 1
                    
        return res
