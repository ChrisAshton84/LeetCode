class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        seen.insert(n);
        
        while (n != 1) {
            int nextNum = 0;
            
            while (n) {
                int digit = n % 10;
                nextNum += (digit * digit);
                n /= 10;
            }
            
            if (seen.count(nextNum))
                return false;
            
            seen.insert(nextNum);
            n = nextNum;
        }
        
        return true;
    }
};
