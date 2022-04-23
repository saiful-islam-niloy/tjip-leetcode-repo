class Solution {
   public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int itr1 = m - 1;
        int itr2 = n - 1;
        int idx = m + n - 1;

        while (itr1 >= 0 && itr2 >= 0) {
            if (nums1[itr1] >= nums2[itr2]) {
                nums1[idx] = nums1[itr1];
                itr1--;
            } else {
                nums1[idx] = nums2[itr2];
                itr2--;
            }
            idx--;
        }

        while (itr1 >= 0) {
            nums1[idx] = nums1[itr1];
            itr1--;
            idx--;
        }

        while (itr2 >= 0) {
            nums1[idx] = nums2[itr2];
            itr2--;
            idx--;
        }
    }
};