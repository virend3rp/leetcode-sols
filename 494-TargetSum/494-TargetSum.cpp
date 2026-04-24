// Last updated: 4/24/2026, 10:12:47 PM
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        int n = nums.size();
        
        for (int num : nums) {
            sum += num;
        }
        if (sum < target || (sum - target) % 2 != 0) {
            return 0;
        }
        int newTarget = (sum - target) / 2;
        vector<vector<int>> dp(n + 1, vector<int>(newTarget + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= newTarget; ++j) {
                dp[i][j] = dp[i - 1][j]; // Exclude the current number
                if (j - nums[i - 1] >= 0) {
                    dp[i][j] += dp[i - 1][j - nums[i - 1]]; // Include the current number
                }
            }
        }
        
        return dp[n][newTarget]; // Return the number of ways to achieve newTarget
    }
};