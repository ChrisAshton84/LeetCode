class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        // S contains at most size() characters (w/ no dashes)
        // Which means size() characters could be split into groups of K
        int max_groups = (S.size() + (K - 1)) / K; // Rounded up
​
        string ret;
        ret.resize(max_groups * (K + 1) - 1); // First group has no dash
​
        int read = S.size() - 1;
        int write = ret.size() - 1;
        int group_pos = 0;
        
        while (read >= 0) {
            char c = S[read--];
​
            while ((read >= 0) && (c == '-'))
                c = S[read--];
​
            if (c != '-') { // If we found a non-dash character
                if (group_pos == K) { // And we're needing a dash
                    ret[write--] = '-';
                    group_pos = 0;
                }
​
                // Convert to upper
                if ((c >= 'a') && (c <= 'z'))
                    c += 'A' - 'a';
​
                // Store
                ret[write--] = c;
​
                group_pos++;
            }
        }
​
        ret.erase(0, write + 1);
        
        return ret;
    }
};
