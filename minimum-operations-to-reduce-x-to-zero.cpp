class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        if (nums.size() == 0)
            return -1; // If no elements, return failure
        
        if (nums[0] == x)
            return 1; // Shortcut
        
        int ret = nums.size() + 1;
        
        int curSum = 0;
        unordered_map<int, int> lhs_sum(nums.size() + 1);
        lhs_sum[0] = 0; // Map <num of lhs> to sum at that point
        for (int i = 0; i < nums.size(); i++) {
            curSum += nums[i];
            
            if (curSum > x) // Once we've reached beyond target val don't need to continue
                break;
            
            lhs_sum[curSum] = i + 1;
        }
        
        curSum = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            curSum += nums[i];
            
            if (curSum > x)
                break;
​
            int complement = x - curSum;
            
            if (lhs_sum.count(complement) > 0) { // If some series of LHS sums to the complement
                int size = lhs_sum[complement] + (nums.size() - i);
                ret = min(ret, size);
            }
        }
        if (ret == nums.size() + 1)
            ret = -1;
​
        return ret;
    }
};
