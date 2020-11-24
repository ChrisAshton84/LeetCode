class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret(2);
​
        unordered_map<int, int> complements(nums.size());
​
        for (int i = 0; i < nums.size(); i++) {
            int val = nums[i];
            int complement = target - val;
​
            if (complements.count(complement) == 1) {
                ret[0] = complements[complement];
                ret[1] = i;
                return ret;
            } else {
                complements[val] = i;
            }
        }
​
        return vector<int>();
    }
};
