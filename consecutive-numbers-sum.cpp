class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int sum = 1;
        int ret = 1;
        
        for (int i = 2; (sum + i) <= N; i++) {
            sum += i;
            
            if (sum == N) {
                ret++;
                break;
            }
​
            // Shifting this sum right adds 1 per element, so subtract sum from N, and see whether that is divisible by i
            int remainder = N - sum;
            if (((remainder / i) * i) == remainder)
                ret++;
        }
        
        return ret;
    }
};
