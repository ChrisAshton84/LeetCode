class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        
        int ret = INT_MIN;
        int max = prices[prices.size() - 1];
        
        for (int i = prices.size() - 2; i >= 0; i--) {
            int profit = max - prices[i];
            if (profit > ret) ret = profit;
            if (prices[i] > max) max = prices[i];
        }
        
        if (ret < 0) ret = 0;
        
        return ret;
    }
};
