class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        set<int> doubles;
​
        for (int i = 0; i < arr.size(); i++) {
            if (doubles.count(arr[i] * 2) > 0) {
                return true;
            } else if (((arr[i] & 1) == 0) && doubles.count(arr[i] / 2)) {
                return true;
            } else {
                doubles.insert(arr[i]);
            }
        }
        
        return false;
    }
};
