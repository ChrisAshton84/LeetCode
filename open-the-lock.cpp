class Solution {
    
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> de; // Store dead-ends in set for faster lookup
        
        for (const auto &x: deadends)
            de.insert(x);
        
        if (de.count("0000") != 0)
            return -1;
        
        queue<string> q; // Combos that need processing
        q.push("0000"); // Start with 0, 0, 0, 0
        de.insert("0000"); // Any visited combo is also a dead end
​
        int moves = 0;
​
        while (q.empty() == false) {
            int level_entries = q.size(); // Entries to process at this level
            
            for (int i = 0; i < level_entries; i++) {
                string c = q.front();
                q.pop();
                
                if (c == target)
                    return moves; // It took 'moves' changes to get here
                
                vector<string> p(8, c); // 8 possible combos off this one
                // Update just needed digits
                p[0][0] = (p[0][0] == '9') ? '0' : p[0][0] + 1;
                p[1][1] = (p[1][1] == '9') ? '0' : p[1][1] + 1;
                p[2][2] = (p[2][2] == '9') ? '0' : p[2][2] + 1;
                p[3][3] = (p[3][3] == '9') ? '0' : p[3][3] + 1;
                
                p[4][0] = (p[4][0] == '0') ? '9' : p[4][0] - 1;
                p[5][1] = (p[5][1] == '0') ? '9' : p[5][1] - 1;
                p[6][2] = (p[6][2] == '0') ? '9' : p[6][2] - 1;
                p[7][3] = (p[7][3] == '0') ? '9' : p[7][3] - 1;
​
                for (const auto &x: p) {
                    if (de.count(x) == 0) {
                        de.insert(x);
                        q.push(x);
                    }
                }
            }
            
            moves++;
        }
​
        return -1;
    }
};
