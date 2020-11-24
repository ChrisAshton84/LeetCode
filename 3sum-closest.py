class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        n_nums = len(nums)
        
        ret_sum = nums[0] + nums[1] + nums[2]
        ret_dist = abs(target - ret_sum)
​
        nums.sort() # Order nums O(n*log(n))
        
        if (target > 0) and (nums[0] > target): # If all numbers are above positive target,
            return ret                          # cannot sum to target
​
        if (target < 0) and (nums[n_nums - 1] < target): # If all numbers are below negative target,
            return ret                                   # cannot sum to target
​
        for i in range(n_nums - 2): # Check all neg values for a complementary pair in remaining numbers
            cur_num = nums[i]       # O(n) * (O(n) from twoSum) = O(n*n)
            complement = target - cur_num
​
            if ((i == 0) or (cur_num != nums[i - 1])):
                closest_sum = self.twoSumClosest(nums[i + 1:], complement) + cur_num # O(n)
                closest_dist = abs(target - closest_sum)
​
                if (closest_dist < ret_dist):
                    ret_sum = closest_sum
                    ret_dist = closest_dist
​
        return ret_sum
​
    def twoSumClosest(self, nums: List[int], target: int) -> int:
        low, high = 0, len(nums) - 1
        closest_dist  = abs(nums[low] + nums[high] - target)
        closest_sum = nums[low] + nums[high]
​
        while (low < high): # Look over all numbers, always incrementing at least one index O(n)
            sum = nums[low] + nums[high]
            dist = abs(target - sum)
            
            if (dist < closest_dist):
                closest_dist = abs(target - sum) # closest_dist = (target - cur_num) -  sum = target - (nums[low] + nums[high] + nums[i])
                closest_sum = sum
            
            if (sum < target): # Grow sum if it's too small
                low += 1
            elif (sum > target): # Shrink sum if it's too large
                high -= 1
            else:
                return closest_sum
​
        return closest_sum
