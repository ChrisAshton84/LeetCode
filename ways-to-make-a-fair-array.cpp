class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        auto isFair = [](vector<int> const n, int skip) {
            int even_sum = 0;
            int odd_sum = 0;
            
            for (int i = 0; i < skip; i++) {
                if ((i & 1) == 0) // even
                    even_sum += n[i];
                else
                    odd_sum += n[i];
            }
            
            for (int i = skip + 1; i < n.size(); i++) {
                if ((i & 1) == 0) // odd (due to skip)
                    odd_sum += n[i];
                else
                    even_sum += n[i];
            }
            
            return (even_sum == odd_sum);
        };
        
        unordered_map<int, int> even_sum; // Map of indices to sums of even index numers, not including current number
        int even_total_sum = 0;
        unordered_map<int, int> odd_sum; // Map of indices to sums of odd index numbers, not including current number
        int odd_total_sum = 0;
​
        for (int i = 0; i < nums.size(); i++) {
            even_sum[i] = even_total_sum;
            odd_sum[i] = odd_total_sum;
​
            if ((i & 1) == 0) // even
                even_total_sum += nums[i];
            else
                odd_total_sum += nums[i];
        }
                
        int ret = 0;
        
        for (int i = 0; i < nums.size() - 1; i++) {
            // Values once this index are removed
            int odd_sum_current = odd_sum[i];
            int even_sum_current = even_sum[i];
            
            odd_sum_current += (even_total_sum - even_sum[i + 1]);
            even_sum_current += (odd_total_sum - odd_sum[i + 1]);
            
            if (odd_sum_current == even_sum_current) {
                ret++;
            }
        }
        
        if (odd_sum[nums.size() - 1] == even_sum[nums.size() - 1]) {
            ret++;
        }
        
        return ret;
    }
};
