class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curSum = 0;
        int maxSum = INT_MIN;
        
        for (const auto &num: nums) {
            curSum = max(num, curSum + num);
            maxSum = max(maxSum, curSum);
        }
        
        return maxSum;
    }
};
