class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret = 0;
​
        while (n) {
            int subSum = 0;
            
            switch (n & 0b1111) {
                case 0b0000:
                    break;
                case 0b0001:
                case 0b0010:
                case 0b0100:
                case 0b1000:
                    subSum = 1;
                    break;
                case 0b0011:
                case 0b0101:
                case 0b0110:
                case 0b1001:
                case 0b1010:
                case 0b1100:
                    subSum = 2;
                    break;
                case 0b0111:
                case 0b1011:
                case 0b1101:
                case 0b1110:
                    subSum = 3;
                    break;
                case 0b1111:
                    subSum = 4;
                    break;
            }
            
            ret += subSum;
            
            n >>= 4;
        }
        
        return ret;
    }
};
