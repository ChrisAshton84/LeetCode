class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> &v1 = (nums1.size() > nums2.size() ? nums1 : nums2); // v1 is longer array
        vector<int> &v2 = (nums1.size() > nums2.size() ? nums2 : nums1); // v2 is shorter array
​
        size_t v1_mid = v1.size() / 2;
        size_t v2_mid = v2.size() / 2;
​
        bool odd_elms = (v1.size() + v2.size()) % 2;
​
        // Early return if array is empty
        if (v2.size() == 0) {
            if (odd_elms)
                return v1[v1_mid];
            else
                return (v1[v1_mid - 1] + v1[v1_mid]) / 2.0;
        }
​
        // Simple solution would be to just merge arrays and pick median, but that is
        // O(1 + m - n), not O(log(m + n))
        //
        // Instead, treat the two sets as independent, but take two given facts into account:
        // 1) the is half-way through the sorted combined values
        // 2) each current vector is already sorted
        //
        // Since each vector is sorted, there will be one point in each vector that dividies
        // the vector between less than or equal the median, and greater than or equal the median.
        //
        // Call these indices v1_le, for v1, and v2_le, for v2
        //
        // Also, since the median is the middle element, the count of elements less than it
        // will equal the count of elements greater than it, across both input vectors.
        //
        // Since each vector is divided by the same value (the median), can compare not just
        // elements w/in a vector but elements across a vector for ordering.
        //
        // Finding the pair of indices that satisfies these conditions identifies possible
        // median values, and simply compare the adjacent elements from each vector to identify
        // correct values.
        //
        // Since v2 is shorter, search its indices to find one satisfying this condition.
        // Further, since v2 is a sorted vector, can do a O(log(v2.size())) binary search for
        // this index.
        //
        // So,
        // 1) v1_le + v2_le = (v1.size() + v2.size() + 1) / 2
        // -> v1_le = (v1.size() + v2.size() + 1) / 2 - v2_le
        //
        // 2) *(v1_le - 1) <= *v2_le
        //    *(v2_le - 1) <= *v1_le
        //    (Substitute v1_le formula above)
​
        // Standard boolean search across v2 elements
        int bs_step = v2.size() / 2;
​
        int v2_le = bs_step; // Start at midpoint of v2
​
        int v1_size = v1.size();
        int v2_size = v2.size();
        int v1_le = (v1_size + v2_size + 1) / 2 - v2_le;
​
        while ((
                    ((v1_le > 0) && (v2_le < v2_size)) &&
                    (v1[v1_le - 1] > v2[v2_le])
               ) ||
               (
                    ((v2_le > 0) && (v1_le < v1_size)) &&
                    (v2[v2_le - 1] > v1[v1_le])
               )) {
​
            // Shrink step size
            bs_step /= 2;
            if (bs_step == 0)
                bs_step = 1;
​
            // Set up code to test condition
            if (
                    (((v1_le - 1) >= 0) && (v2_le < v2_size)) &&
                    (v1[v1_le - 1] > v2[v2_le])
                ) {
​
                // search towards end
                v2_le += bs_step;
            } else if
                (
                    (((v2_le - 1) >= 0) && (v1_le < v1_size)) &&
                    (v2[v2_le - 1] > v1[v1_le])
                ) {
​
                // search towards beginning
                v2_le -= bs_step;
            } else
                // search found match
                break;
​
            // Calc v1 le based on v2
            v1_le = (v1_size + v2_size + 1) / 2 - v2_le;
        }
​
        if (odd_elms) {
            if (v1_le == 0)
                return v2[v2_le - 1];
            else if (v2_le ==0)
                return v1[v1_le - 1];
​
            return std::max(v1[v1_le - 1], v2[v2_le - 1]);
        } else {
            int left_val;
​
            if (v1_le == 0)
                left_val = v2[v2_le - 1];
            else if (v2_le == 0)
                left_val = v1[v1_le - 1];
            else
                left_val = std::max(v1[v1_le - 1], v2[v2_le - 1]);
​
            int right_val;
​
            if (v1_le >= v1_size)
                right_val = v2[v2_le];
            else if (v2_le >= v2_size)
                right_val = v1[v1_le];
            else
                right_val = std::min(v1[v1_le], v2[v2_le]);
​
            return (left_val + right_val) / 2.0;
        }
    }
};
