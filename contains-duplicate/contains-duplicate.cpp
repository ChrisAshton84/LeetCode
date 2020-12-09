class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        
        for (const auto &i: nums) {
            if (seen.count(i) > 0)
                return true;
            
            seen.emplace(i);
        }
        
        return false;
    }
};
