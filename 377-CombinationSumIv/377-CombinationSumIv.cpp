// Last updated: 4/24/2026, 10:13:23 PM
class Solution {
public:
int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= target; i++) {
            for (int num : nums) {
                if (i >= num)
                    dp[i] += dp[i - num];
            }
        }

        return dp[target];
}
};