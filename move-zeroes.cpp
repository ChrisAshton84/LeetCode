class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int r = 0;
        int w = 0;
​
        for (; r < nums.size(); r++) {
            while ((r < nums.size()) && (nums[r] == 0))
                r++;
            
            if (r == nums.size())
                break;
            
            nums[w++] = nums[r];
        }
        
        for (; w < nums.size(); w++)
            nums[w] = 0;
    }
};
