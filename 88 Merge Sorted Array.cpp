class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //increasing or same number
        //m and n can be different
        int w = m - 1;
        int v = n - 1;
        //we fill nums1 backwards since we can save the data from nums1 in itself until we need it
        for (int i = m + n - 1; i > -1; i--) { // TODO:review this
            //check which number is bigger, do that first
            //we also want to use nums1 if v <= -1
            //except when w <= -1
            if (w > -1 && (v <= -1 || nums1[w] > nums2[v])) {
                nums1[i] = nums1[w];
                w--;
            }
            else {
                nums1[i] = nums2[v];
                v--;
            }
        }
    }
};