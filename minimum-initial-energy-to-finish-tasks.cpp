class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        if (tasks.size() == 0)
            return 0;
        
        // Sort tasks by excess energy
        list<vector<int>> ordered;
        
        for (int i = 0; i < tasks.size(); i++) {
            ordered.push_back(tasks[i]);
        }
        
        // Sort the array
        ordered.sort([](const vector<int>& v1, const vector<int>& v2)->bool {
            int e1 = v1[1] - v1[0];
            int e2 = v2[1] - v2[0];
            
            // Return true if first is before second
            if (e1 < e2)
                return true;
            else if (e1 == e2)
                if (v1[0] < v2[0])
                    return true;
            
            return false;
        });
        
        int current_energy = ordered.front()[1];
        
        for (auto it = ++(ordered.cbegin()); it != ordered.cend(); it++) {
            int new_min = current_energy + (*it)[0];
            current_energy = max(new_min, (*it)[1]);
        }
        
        return current_energy;
    }
};
