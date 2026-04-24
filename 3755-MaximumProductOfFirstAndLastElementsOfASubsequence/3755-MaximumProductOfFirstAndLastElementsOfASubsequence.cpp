// Last updated: 4/24/2026, 10:03:59 PM
class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int n = nums.size();
    
        if (m == 1) {
            long long maxAbsVal = LLONG_MIN;
            for (int val : nums) {
                maxAbsVal = max(maxAbsVal, 1LL * val * val);
            }
            return maxAbsVal;
        }
    
        vector<int> suffixMax(n), suffixMin(n);
        suffixMax[n - 1] = suffixMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixMax[i] = max(nums[i], suffixMax[i + 1]);
            suffixMin[i] = min(nums[i], suffixMin[i + 1]);
        }
    
        long long maxProduct = LLONG_MIN;
    
        for (int i = 0; i <= n - m; i++) {
            int firstElement = nums[i];
            int minLastPos = i + m - 1;
    
            if (minLastPos < n) {
                long long prod1 = 1LL * firstElement * suffixMax[minLastPos];
                long long prod2 = 1LL * firstElement * suffixMin[minLastPos];
                maxProduct = max(maxProduct, max(prod1, prod2));
            }
        }
    
        return maxProduct;
}
};