class Solution {
private:
    int robIndex(const vector<int> &nums, int idx, vector<int> &maxAtIdx) {
        if (maxAtIdx[idx] > -1)
            return maxAtIdx[idx];
​
        if (idx >= nums.size() - 2) { // Only one option - only this house
            maxAtIdx[idx] = nums[idx];
            return nums[idx];
        }
        
        int maxSkipOne = nums[idx] + robIndex(nums, idx + 2, maxAtIdx);
        int maxSkipTwo = -1;
        if (idx + 3 < nums.size())
            maxSkipTwo = nums[idx] + robIndex(nums, idx + 3, maxAtIdx);
        
        maxAtIdx[idx] = max(maxSkipOne, maxSkipTwo);
        return maxAtIdx[idx];
    }
public:
    int rob(vector<int>& nums) {
        vector<int> maxAtIdx(nums.size(), -1);
​
        if (nums.size() == 0)
            return 0;
​
        if (nums.size() == 1)
            return nums[0];
        
        return max(robIndex(nums, 0, maxAtIdx), robIndex(nums, 1, maxAtIdx));
    }
};
