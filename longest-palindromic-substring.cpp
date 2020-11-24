class Solution {
public:
    string longestPalindrome(string s) {
            int max_odd_pos = 0;
            int max_odd_rad = 0; // Radius is the number of additional elements surrounding base element
​
            int cur_pos = 1;
            int s_len = s.length();
​
            int max_even_pos = -1;
            int max_even_rad = -1;
        
            if (s_len > 1)
                if (s[0] == s[1]) {
                    max_even_pos = 0;
                    max_even_rad = 0;
                }
​
            if (s_len == 0)
                return string("");
​
            // Search all strings (length is up to 1k, this won't take long)
            while ((cur_pos + max_odd_rad < s_len) ||
                   (cur_pos + max_even_rad + 1 < s_len)) {
                // Don't search beyond bounds of string
                int max_rad = (cur_pos < (s_len / 2)) ? cur_pos : s_len - cur_pos - 1;
​
                // First detect the start of an odd palindrome
                // These have a central point and pairs of equal letters surrounding it
                int cur_rad = 0;
                while ((cur_rad < max_rad) &&
                       (s[cur_pos + cur_rad + 1] == s[cur_pos - cur_rad - 1]))
                    cur_rad++;
​
                if (cur_rad > max_odd_rad) {
                    max_odd_pos = cur_pos;
                    max_odd_rad = cur_rad;
                }
​
                // Now look for the start of an 'even' palindrome
                // These have a central pair and then surrounding pairs of equal letters
                if (s[cur_pos] == s[cur_pos + 1]) {
                    cur_rad = 0;
                    while ((cur_rad < max_rad) &&
                           (s[cur_pos + cur_rad + 2] ==  s[cur_pos - cur_rad - 1]))
                        cur_rad++;
​
                    if (cur_rad > max_even_rad) {
                        max_even_pos = cur_pos;
                        max_even_rad = cur_rad;
                    }
                }
​
                cur_pos++;
            }
​
            if (max_odd_rad > max_even_rad)
                return s.substr(max_odd_pos - max_odd_rad, max_odd_rad * 2 + 1);
            else
                return s.substr(max_even_pos - max_even_rad, max_even_rad * 2 + 2);
    }
};
