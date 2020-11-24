class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long unique = 0;
        long first = 0;
        long second = 0;
        long third = 0;
​
        for (auto& x : nums) {
            if (unique == 0) {
                unique = 1;
                first = x;
            } else if (unique == 1) {
                if (x != first) {
                    unique = 2;
                    if (x > first) {
                        second = first;
                        first = x;
                    } else
                        second = x;
                }
            } else if (unique == 2) {
                if ((x != first) && (x != second)) {
                    unique = 3;
                    if (x > first) {
                        third = second;
                        second = first;
                        first = x;
                    } else if (x > second) {
                        third = second;
                        second = x;
                    } else
                        third = x;
                }
            } else {
                if ((x != first) && (x != second) && (x != third)) {
                    if (x > first) {
                        third = second;
                        second = first;
                        first = x;
                    } else if (x > second) {
                        third = second;
                        second = x;
                    } else if (x > third)
                        third = x;
                }
            }
        }
        
        if (unique == 3)
            return third;
​
        return first;
    }
};
