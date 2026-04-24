// Last updated: 4/24/2026, 10:05:26 PM
class Solution {
public:
    int numberOfWays(int n, int x) {
        const int MOD = 1e9 + 7;
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;

        for (int j = 1; (int)pow(j, x) <= n; j++) {
            int val = (int)pow(j, x);
            for (int i = n; i >= val; i--) {  // backwards = each j used once
                dp[i] = (dp[i] + dp[i - val]) % MOD;
            }
        }
        return dp[n];
    }
};