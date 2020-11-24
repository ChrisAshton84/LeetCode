class Solution {
public:
    bool isMatch(string s, string p) {
            int s_pos = 0, p_pos = 0;
​
            int s_len = s.length();
            int p_len = p.length();
​
            while (p_pos < p_len) {
                char p_chr = p[p_pos];
​
                bool star = ((p_pos + 1 < p_len) && (p[p_pos + 1] == '*'));
​
                if (star) {
                    bool valid_star = 1;
​
                    while ((s_pos < s_len) && (valid_star)) {
                        // Need to check recursively here -
                        if (isMatch(s.substr(s_pos, string::npos), p.substr(p_pos + 2, string::npos)))
                            return true;
                        
                        switch (p_chr) {
                            case 'a' ... 'z':
                                if (s[s_pos] == p_chr)
                                    s_pos++;
                                else
                                    valid_star = false;
                                    break;
                            case '.':
                                s_pos++;
                                continue;
                            default:
                                break;
                        }
                    }
​
                    p_pos += 2;
                } else {
                    if (s_pos >= s_len)
                        return false;
​
                    switch (p_chr) {
                        case 'a' ... 'z':
                            if (s[s_pos] == p_chr)
                                s_pos++;
                            else
                                return false;
                            break;
                        case '.':
                            s_pos++;
                            break;
                        default:
                            break;
                    }
​
                    p_pos++;
                }
            }
​
            if (s_pos != s_len)
                return false;
​
            return true;
    }
};
