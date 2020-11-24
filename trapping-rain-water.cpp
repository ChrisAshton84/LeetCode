class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 3) // Need two columns and a gap to store water
            return 0;
​
        int ret = 0;
        int size = height.size();
        
        bool some_peak = false;
        bool some_valley = false; // Pre-determine whether there's any buckets
​
        vector<int> rhs_max(size); // compute max height to the right for every position
​
        int rhs_cur_max = 0;
        
        for (int i = height.size() - 1; i >= 0; i--) {
            if (height[i] > rhs_cur_max)
                rhs_cur_max = height[i];
            
            if (some_peak == false) {
                if ((i > 0) && (height[i - 1] < height[i]))
                    some_peak = true;
            } else if (some_valley == false) {
                if ((i > 0) && (height[i - 1] > height[i]))
                    some_valley = true;
            }
​
            rhs_max[i] = rhs_cur_max;
        }
        
        if (some_valley == false) // Early exit if order doesn't allow for any buckets (decrease, gap, increase)
            return 0;
        
        int lhs_cur_max = 0;
        for (int i = 0; i < height.size(); i++) { 
            if (height[i] > lhs_cur_max)
                lhs_cur_max = height[i];
            
            int containedHeight = min(lhs_cur_max, rhs_max[i]);
            
            ret += containedHeight - height[i];
        }
        
        return ret;
    }
};
