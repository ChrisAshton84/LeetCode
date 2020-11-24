class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int minIdx = 0;
        A[0] *= A[0];
        int minVal = A[0];
        
        for (int i = 1; i < A.size(); i++) {
            A[i] *= A[i];
            if (A[i] < minVal) {
                minIdx = i;
                minVal = A[i];
            }
        }
        
        int l = minIdx - 1;
        int r = minIdx + 1;
        
        vector<int> res;
        res.reserve(A.size());
        
        res.push_back(A[minIdx]);
    
        while ((l >= 0) || (r <= A.size() - 1)) {
            if (l < 0)
                res.push_back(A[r++]);
            else if (r > (A.size() - 1))
                res.push_back(A[l--]);
            else
                if (A[l] < A[r])
                    res.push_back(A[l--]);
                else
                    res.push_back(A[r++]);
        }
        
        return res;
    }
};
