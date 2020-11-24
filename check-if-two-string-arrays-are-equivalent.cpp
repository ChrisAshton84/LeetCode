class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        if ((word1.size() == 0) && (word2.size() == 0))
            return true;
        
        int w1len = 0;
        for (auto& w: word1)
            w1len += w.size();
        
        int w2len = 0;
        for (auto& w: word2)
            w2len += w.size();
        
        if (w1len != w2len)
            return false;
        
        // Strings are the same length at this point
        int w1_idx = 0;
        int w2_idx = 0;
        int s1_idx = 0;
        int s2_idx = 0;
        while (true) {
            if (s1_idx >= word1[w1_idx].length()) {
                if (w1_idx + 1 >= word1.size())
                    break;
                else {
                    s1_idx = 0;
                    w1_idx++;
                }
            }
            
            if (s2_idx >= word2[w2_idx].length()) {
                if (w2_idx + 1 >= word2.size())
                    break;
                else {
                    s2_idx = 0;
                    w2_idx++;
                }
            }
​
            char c1 = word1[w1_idx][s1_idx++];
            char c2 = word2[w2_idx][s2_idx++];
​
            if (c1 != c2)
                return false;
        }
        
        return true;
    }
};
