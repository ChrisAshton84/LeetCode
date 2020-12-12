class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int h = s.size() - 1;
        
        while (l < h) {
            while (((s[l] < 'a') || (s[l] > 'z')) &&
                   ((s[l] < 'A') || (s[l] > 'Z')) &&
                   ((s[l] < '0') || (s[l] > '9'))) {
                l++;
                if (l >= h)
                    return true;
            }
            
            char l_c = s[l];
            
            if ((l_c >= 'A') && (l_c <= 'Z'))
                l_c += ('a' - 'A');
            
            while (((s[h] < 'a') || (s[h] > 'z')) &&
                   ((s[h] < 'A') || (s[h] > 'Z')) &&
                   ((s[h] < '0') || (s[h] > '9'))) {
                h--;
                if (l >= h)
                    return true;
            }
            
            char h_c = s[h];
            
            if ((h_c >= 'A') && (h_c <= 'Z'))
                h_c += ('a' - 'A');
            
            if (l_c != h_c) {
                cout << "Fail at " << l << ":" << l_c << " != " << h << ":" << h_c << endl;
                return false;
            }
            
            l++;
            h--;
        }
        
        return true;
    }
};
