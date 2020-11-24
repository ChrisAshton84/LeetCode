class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        auto size = code.size();
​
        vector<int> ret(size, 0);
​
        if (k == 0) {
            return ret;
        }
​
        // Calculate 0th element
        auto sum = 0;
        auto base = k > 0 ? 0 : size; // If k is negative walk back from code[size]
        auto step = k > 0 ? -1 : 1;
        auto i = k;
        
        while (i != 0) {
            sum += code[base + i];
            i += step;
        }
        
        auto add_offset = k > 0 ? (k + 1) % size : 0; // Always add next unused to the right (wrapping)
        auto sub_offset = k > 0 ? 1 : size + k; // Always sub left-most used element (wrapping)
        
        for (i = 0; i < size; i++) {
            ret[i] = sum; // Use computed sum
            
            // Now update sum - will add one to the right 
            sum += code[add_offset];
            sum -= code[sub_offset];
            
            add_offset = (add_offset + 1) % size;
            sub_offset = (sub_offset + 1) % size;
        }
        
        return ret;
    }
};
