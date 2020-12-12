class Solution {
public:
    int firstUniqChar(string s) {
        if (s.size() == 0)
            return -1;
        
        if (s.size() == 1)
            return 0;
        
        unordered_map<char, int> singleChar;
        unordered_set<char> multiChar;
        
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (multiChar.count(c))
                continue;
            
            if (singleChar.count(c)) {
                singleChar.erase(c);
                multiChar.insert(c);
            } else
                singleChar[c] = i;
        }
        
        if (singleChar.size() == 0)
            return -1;
        
        int min = s.size() - 1;
        
        for (const auto &p: singleChar) {
            if (p.second < min)
                min = p.second;
        }
        
        return min;
    }
};
