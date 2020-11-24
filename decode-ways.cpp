class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 1){
            if (s[0] == '0')
                return 0;
            else
                return 1;
        }
        
        int i = 0;
        int ret = 1;
        
        auto fib = [](int target)->int {
            if (target == 0)
                return 0;
            
            if (target == 1)
                return 1;
​
            int n_m2 = 0;
            int n_m1 = 1;
            int n;
            int i = 2;
            
            while (i++ <= target) {
                n = n_m1 + n_m2;
                n_m2 = n_m1;
                n_m1 = n;
            }
            
            return n;
        };
        
        auto onesAndTwos = [](string s, int pos)->int {
            int i = pos;
            
            while ((i + 1) < s.size()) {
                char c = s[i + 1];
                if ((c != '1') && (c != '2'))
                    break;
                
                i++;
            }
            
            // i contains last position w/ 1 or 2
            return i;            
        };
​
        while(i < s.size()) {
            switch (s[i]) {
                case '0':
                    return 0;
                case '1':
                case '2':
                    if ((i + 1) < s.size()) {
                        int end = onesAndTwos(s, i);
                        int fibLen = end - i + 1;                        
                     
                        if ((end + 1) < s.size()) { // If there's a character following end
                            char c2 = s[end + 1];
​
                            if (c2 != '0') {  // '1', '0' or '2', '0' invalid independently
                                if (s[end] == '1')                     // '1' followed by '1'-'9' can be end of pattern
                                    fibLen += 2;
                                else if ((c2 >= '1') && (c2 <= '6'))   // '2' followed by '1'-'6' can be end of pattern
                                    fibLen += 2;
                                else
                                    fibLen += 1;
                            }
                            
                            i = end + 2; // skip past pattern
                        } else {
                            fibLen += 1;
                            i = end + 1;
                        }
                        
                        ret *= fib(fibLen);
                    } else
                        i++;
                    break;
                default:
                    i++;
                    break;
            }
        }
        
        return ret;
    }
};
