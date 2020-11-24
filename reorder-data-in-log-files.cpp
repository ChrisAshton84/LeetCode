class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        // Process all elements in logs
        // If it's a letter log leave it be, go to next
        // If it's a digit log, remove it and put it at the end
        
        // Removing is costly (causes needless shifting)
        // So just do two passes and store in new array
        vector<string> ret_letter;
        vector<string> ret_digit;
        
        ret_letter.reserve(logs.size());
        ret_digit.reserve(logs.size());
        
        for (auto& log: logs) {
            char next_c = log[log.find(' ') + 1];
            if ((next_c >= 'a') && (next_c <= 'z')) // letter log
                ret_letter.push_back(log);
            else // digit_log
                ret_digit.push_back(log);
        }
        auto sortLetterLog = [](string a, string b)->bool {
            int idx_a = a.find(' ');
            int idx_b = b.find(' ');
            
            int logCmp = a.compare(idx_a, string::npos, b, idx_b, string::npos);
            
            if (logCmp < 0)
                return true;
            
            if (logCmp > 0)
                return false;
            
            int tagCmp = a.compare(0, idx_a - 1, b, 0, idx_b - 1);
            
            if (tagCmp <= 0)
                return true;
            
            return false;
        };
        
        sort(ret_letter.begin(), ret_letter.end(), sortLetterLog);
        
        ret_letter.insert(ret_letter.end(), ret_digit.begin(), ret_digit.end());
​
        return ret_letter;
    }
};
