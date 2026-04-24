// Last updated: 4/24/2026, 10:13:46 PM
class Solution {
public:
    int f(int ind, int prev_index, vector<int>& nums, int n, vector<vector<int>>& dp) {
        if (ind == n) {
            return 0;
        }

        if (dp[ind][prev_index + 1] != -1) {
            return dp[ind][prev_index + 1];
        }
        int skip = f(ind + 1, prev_index, nums, n, dp);
        int take = 0;
        if (prev_index == -1 || nums[ind] > nums[prev_index]) {
            take = 1 + f(ind + 1, ind, nums, n, dp);
        }

        dp[ind][prev_index + 1] = max(take, skip);
        return dp[ind][prev_index + 1];
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return f(0, -1, nums, n, dp);
    }
};
