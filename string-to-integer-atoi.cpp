class Solution {
public:
    int myAtoi(string s) {
        long ret = 0;
​
        int s_len = s.length();
​
        int num_start = 0;
        int sign = 1;
​
        for (int i = 0; i < s_len; i++) {
            if (s[i] == ' ')
                num_start++;
            else if (s[i] == '+') {
                num_start++;
                break;
            } else if (s[i] == '-') {
                num_start++;
                sign = -1;
                break;
            } else if ((s[i] >= '0') && (s[i] <= '9'))
                break;
            else
                return 0;
        }
​
        for (int i = num_start; i < s_len; i++) {
            if ((s[i] < '0') || (s[i] > '9'))
                return ret;
​
            int digit = s[i] - '0';
​
            ret *= 10;
​
            if (sign > 0) {
                ret += digit;
​
                if (ret > INT32_MAX)
                    return INT32_MAX;
            } else {
                ret -= digit;
​
                if (ret < INT32_MIN)
                    return INT32_MIN;
            }
        }
​
        return ret;
    }
};
