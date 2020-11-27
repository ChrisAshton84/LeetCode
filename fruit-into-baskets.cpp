class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int fruit0 = -1;
        int fruit1 = -1; // Use -1 to signify no fruit there
        int count0 = 0;
        int count1 = 0;  // Total of the fruit in this valid pattern
        int repeat0 = 0;
        int repeat1 = 0; // Length of last string of the same fruit
        int prev = -1;   // Which fruit was last picked
        int max = 0;     // Max picked so far
        
        for (auto &x: tree) {
            if (fruit0 == -1) {
                fruit0 = x;
                
                count0 = 1;
                repeat0 = 1;
                
                prev = 0;
            } else if (x == fruit0) {
                count0++;
                repeat0++;
                
                if (prev != 0) {
                    repeat1 = 0;
                    prev = 0;
                }
            } else if (fruit1 == -1) {
                fruit1 = x;
                
                count1 = 1;
                repeat1 = 1;
                
                repeat0 = 0;
                prev = 1;
            } else if (x == fruit1) {
                count1++;
                repeat1++;
                
                if (prev != 1) {
                    repeat0 = 0;
                    prev = 1;
                }
            } else {
                // Can't put fruit in empty / existing basket
                // Check to see whether baskets are a max
                if ((count0 + count1) > max) {
                    max = count0 + count1;
                }
                
                if (prev == 0) { // Previous fruit was type 0, so replace type 1
                    count0 = repeat0; // Only the last string of type 0 can continue on
                    repeat0 = 0;      // Break 0's string
                    fruit1 = x; // Set new fruit info
                    count1 = 1;
                    repeat1 = 1;
                    prev = 1; // Point to new fruit
                } else {
                    count1 = repeat1;
                    repeat1 = 0;
                    fruit0 = x;
                    count0 = 1;
                    repeat0 = 1;
                    prev = 0;
                }
            }
        }
        
        if ((count0 + count1) > max) {
            max = count0 + count1;
        }
        
        return max;
    }
};
