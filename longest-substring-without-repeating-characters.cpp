class Solution {
public:
        int lengthOfLongestSubstring(string s) {
            if (s.size() == 0) // empty string has no substring
                return 0;
​
            // Track the last time each character was seen
            // s is of type char, max length is 5000,
            // so use up to 256 shorts to track previous locations
            short last_idx[256] = { 0 }; // index of 0 means not yet found
​
            int ret = 1; // At least 1 character will count
​
            short substr_start = 1; // Bias indices by 1 so 0 can mean not found
​
            for (short cur = 1; cur <= s.size(); cur++) {
                char letter = s[cur - 1];
                short prev_idx = last_idx[letter];
​
                if (prev_idx >= substr_start) { // If letter has been found w/in this substr
                    int substr_len = cur - substr_start;  // This delimits a substr
​
                    substr_start = prev_idx + 1; // Move up past the previous char, forming a new valid substr
​
                    if (substr_len > ret)
                        ret = substr_len;
                }
                
                last_idx[letter] = cur;
            }
​
            // Test for end of string being substr
            if (s.size() + 1 - substr_start > ret)
                ret = s.size() + 1 - substr_start;
​
            return ret;
            
    }
};
