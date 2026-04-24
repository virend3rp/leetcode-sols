// Last updated: 4/24/2026, 10:10:05 PM
class Solution {
public:
    int dp[38];

    Solution() {
        memset(dp, -1, sizeof(dp));
    }
    int tribonacci(int n) {
        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;
        if(dp[n] != -1) return dp[n];
        return dp[n] = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
    }
};
