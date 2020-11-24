class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3)
            return false;
        
        bool peak = false;
        
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] == arr[i - 1])
                return false;
​
            if (arr[i] > arr[i - 1]) {
                if (peak)
                    return false;
            }
            
            if (arr[i] < arr[i - 1]) {
                if (i == 1)
                    return false;
                if (peak == false)
                    peak = true;
            }
        }
        
        if (peak)
            return true;
        return false;
    }
};
