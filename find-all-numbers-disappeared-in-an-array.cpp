class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i] - 1;
            if (x >= nums.size())
                x -= nums.size();
            
            if (nums[x] <= nums.size())
                nums[x] += nums.size();
        }
        
        vector<int> ret;
​
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= nums.size()) {
                ret.push_back(i + 1);
            }
        }
​
        return ret;
    }
};
