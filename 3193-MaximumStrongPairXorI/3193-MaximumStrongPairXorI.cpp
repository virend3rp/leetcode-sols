// Last updated: 4/24/2026, 10:05:09 PM
class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0, n = nums.size(), l = 0;
        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++) {
                if (nums[j] > 2 * nums[i]) break;
                res = max(res, nums[i] ^ nums[j]);
            }
        return res;
    }
};