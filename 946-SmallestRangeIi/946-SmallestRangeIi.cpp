// Last updated: 4/24/2026, 10:11:07 PM
class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int initialScore = nums[n-1] - nums[0]; // Initial max - min

        int minScore = initialScore;
        int left = nums[0] + k, right = nums[n-1] - k;

        for (int i = 0; i < n - 1; i++) {
            int newMax = max(right, nums[i] + k);
            int newMin = min(left, nums[i+1] - k);
            minScore = min(minScore, newMax - newMin);
        }

        return minScore;
    }
};
