class Solution {
public:
    int climbStairs(int n) {
        if (n == 0)
            return 1;
        
        if (n == 1)
            return 1;
        
        int dp2 = 1;
        int dp1 = 1;
        
        int dp0;
        
        for (int i = 2; i <= n; i++) {
            dp0 = dp1 + dp2;
            dp2 = dp1;
            dp1 = dp0;
        }
        
        return dp0;
    }
};
