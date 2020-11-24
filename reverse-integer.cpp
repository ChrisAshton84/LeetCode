class Solution {
public:
    int reverse(int x) {
            long temp = 0;
            char sign = (x < 0 ? 1 : -1);
​
            x *= sign;
​
            while (x) {
                int temp_dig = x % 10;
​
                temp *= 10;
                temp += temp_dig;
​
                x /= 10;
            }
​
            temp *= sign;
​
            if ((temp > INT32_MAX) || (temp < INT32_MIN))
                temp = 0;
​
            return temp;
    }
};
