class Solution {
public:
    int findNumbers(vector<int>& nums) {
        auto evenDigits = [](int x)->bool {
            // x is guaranteed to be between 1 and 1,000,000
            if (x >= 1000000) 
                return false;
            else if (x >= 100000)
                return true;
            else if (x >= 10000)
                return false;
            else if (x >= 1000)
                return true;
            else if (x >= 100)
                return false;
            else if (x >= 10)
                return true;
            else
                return false;
        };
        
        int ret = 0;
        for (auto &x : nums) {
            if (evenDigits(x))
                ret++;
        }
        
        return ret;
    }
};
