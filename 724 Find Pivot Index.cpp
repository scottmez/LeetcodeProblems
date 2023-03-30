class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int out = -1;
        int *prefixSumLeft = new int[n];
        int *prefixSumRight = new int[n];
        prefixSumLeft[n-1] = nums.at(n-1); // sum from right to left
        prefixSumRight[0] = nums.at(0); // sum from left to right
        for (size_t i = 1; i < n; i++) { // i = 1 ... n-1
            prefixSumRight[i] = nums.at(i) + prefixSumRight[i-1];
            //std::cout << prefixSumRight[i] << '\n';
        }
        for (size_t i = n-1; i > 0; i--) { // i = n-1 ... 1
            prefixSumLeft[i-1] = nums.at(i-1) + prefixSumLeft[i];
            // 0 ... n-2 = 0 ... n-2, 1 ... n-1
            //std::cout << prefixSumLeft[i] << '\n';
        }
        if (prefixSumRight[n-1] - prefixSumRight[0] == 0) {
            out = 0;
            goto END;
        }
        for (size_t i = 1; i < n-1; i++) {
            if (prefixSumRight[i-1] == prefixSumLeft[i+1]) {
                    out = i;
                    goto END;
                }
        }
        if (prefixSumLeft[0] - prefixSumLeft[n-1] == 0) {
            out = n-1;
        }
        END:
        delete[] prefixSumRight;
        delete[] prefixSumLeft;
        return out;
    }
};