class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ok = 0;
        
        vector<int> tmpNums(nums.size());
        
        for (auto &x: nums) {
            if (x != val)
                tmpNums[ok++] = x;
        }
        
        nums = tmpNums;
​
        return ok;
    }
};
