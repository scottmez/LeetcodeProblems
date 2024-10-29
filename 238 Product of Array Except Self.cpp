
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int rev_prod = nums.at(n-1); //reverse product
        vector<int> result = nums;
        for (int i = 1; i < n - 1; i++) {
            result.at(i) = result.at(i - 1) * result.at(i);
        }
        //handle special case where only one number is needed
        result.at(n-1) = result.at(n-2);
        for (int i = n - 2; i != 0; i--) {
            result.at(i) = result.at(i-1) * rev_prod;
            rev_prod *= nums.at(i);
        }
        result.at(0) = rev_prod;
        return result;
    }
};