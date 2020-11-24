class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int prevMax = arr[arr.size() - 1];
​
        for (int i = arr.size() - 2; i >= 0; i--) {
            int nextMax = max(arr[i], prevMax);
            arr[i] = prevMax;
            prevMax = nextMax;
        }
        
        arr[arr.size() - 1] = -1;
​
        return arr;
    }
};
