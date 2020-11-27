class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> smallest;
        vector<int> ret(T.size(), 0);
        
        for (int i = T.size() - 1; i >= 0; i--) {
            int val = T[i];
            
            // Remove all smaller entries from the stack
            while ((smallest.size() > 0) && (val >= T[smallest.top()]))
                smallest.pop();
            
            // Left with only entries which are higher than this, in order they were added
            // So the top is the most recent
            if (smallest.size() > 0)
                ret[i] = smallest.top() - i;
                
            smallest.push(i);
        }
        
        return ret;
    }
};
