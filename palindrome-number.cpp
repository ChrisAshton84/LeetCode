class Solution {
public:
    bool isPalindrome(int x) {
            if (x < 0) return false;
​
            char digit[12] = { 0 };
​
            int digits = 0;
            int tmp_x = x;
​
            while (tmp_x) {
                char num = tmp_x % 10;
                digit[digits++] = num;
                tmp_x /= 10;
            }
​
            if (digits & 1) { // If odd palindrome
                int mid = digits / 2;
​
                for (int i = 1; i <= mid; i++) {
                    if (digit[mid - i] != digit[mid + i])
                        return false;
                }
            } else { // If even palindrome
                int mid = (digits / 2) - 1;
​
                for (int i = 0; i <= mid; i++) {
                    if (digit[mid - i] != digit[mid + i + 1])
                        return false;
                }
            }
​
            return true;
    }
};
