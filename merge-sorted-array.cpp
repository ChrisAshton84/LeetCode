class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0;
        int j = 0;
        
        vector<int> res;
        res.resize(m + n);
        
        for (int idx = 0; idx < m + n; idx++) {
            if (i >= m)
                res[idx] = nums2[j++];
            else if (j >= n)
                res[idx] = nums1[i++];
            else {
                if (nums1[i] < nums2[j])
                    res[idx] = nums1[i++];
                else
                    res[idx] = nums2[j++];
            }
        }
        
        nums1 = res;
    }
};
