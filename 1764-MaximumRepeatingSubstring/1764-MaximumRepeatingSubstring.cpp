// Last updated: 4/24/2026, 10:08:31 PM
class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int n = sequence.size();
        int m = word.size();
        vector<int> dp(n + 1, 0);
        int maxK =0;
        for (int i = m - 1; i < n; ++i) {
            // Check if the substring ending at `i` matches `word`
            if (sequence.substr(i - m + 1, m) == word) {
                dp[i + 1] = dp[i - m + 1] + 1;
                maxK = max(maxK, dp[i + 1]);
            }
        }

        return maxK;
    }
};