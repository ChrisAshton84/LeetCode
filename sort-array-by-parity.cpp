class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int l = 0;
        int r = A.size() - 1;
        
        auto even = [](int x)->bool {
            if ((x & 1) == 0)
                return true;
            return false;
        };
        
        while (l < r) {
            while (even(A[l]) && (l < r))
                l++;
​
            while (!(even(A[r])) && (l < r))
                r--;
            
            if (l < r) {
                int tmp = A[r];
                A[r] = A[l];
                A[l] = tmp;
​
                l++;
                r--;
            }
        }
        
        return A;
    }
};
