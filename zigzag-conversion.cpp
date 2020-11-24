class Solution {
public:
    string convert(string s, int numRows) {
            if (numRows == 1)
                return s;
​
            string ret("");
​
            auto s_len = s.length();
            auto loop_len = (numRows * 2) - 2;
​
            // First and last rows display pattern w/o diagonal mess
            int row = 0;
            for (auto c = row; c < s_len; c += loop_len) {
                ret.push_back(s[c]);
            }
​
            for (row = 1; row < numRows - 1; row++) {
                for (auto c = row; c < s_len; ) {
                    ret.push_back(s[c]);
​
                    c += loop_len - (row * 2);
​
                    if (c < s_len)
                        ret.push_back(s[c]);
​
                    c += row * 2;
                }
            }
​
            // First and last rows display pattern w/o diagonal mess
            row = numRows - 1;
            for (auto c = row; c < s_len; c += loop_len) {
                ret.push_back(s[c]);
            }
​
            return ret;
    }
};
