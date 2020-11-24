class Solution {
public:
    string getSmallestString(int n, int k) {
        string ret(n, 'a'); // Initialize smallest possible (lexographically)
        int sum = n;        // Smallest possible is all a's and sums to n
        
        if (n == 0)
            return ret;
        
        int diff = k - n;
        
        // Each character can add up to 25 more (b is 1 more than a, z is 25 more)
        // Add values from right to left
        int next_idx = n - 1;
        while (diff > 0) {
            if (diff >= 25) {
                ret[next_idx--] = 'z';
                diff -= 25;
            } else {
                ret[next_idx--] = 'a' + diff;
                diff -= diff;
            }
        }
        
        return ret;
    }
};
