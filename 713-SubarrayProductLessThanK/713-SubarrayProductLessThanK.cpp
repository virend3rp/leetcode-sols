// Last updated: 4/24/2026, 10:11:57 PM
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;  // product is always >= 1

        int left = 0, product = 1, count = 0;

        for (int right = 0; right < nums.size(); right++) {
            product *= nums[right];

            while (product >= k)
                product /= nums[left++];

            count += right - left + 1;
        }
        return count;
    }
};