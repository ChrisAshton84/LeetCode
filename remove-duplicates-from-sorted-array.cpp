class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int w = 0;
        
        for (int r = 0; r < nums.size(); r++) {
            while (((r + 1) < nums.size()) && (nums[r] == nums[r + 1]))
                r++;
            
            nums[w++] = nums[r];
        }
        
        return w;
    }
};
