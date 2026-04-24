// Last updated: 4/24/2026, 10:04:17 PM
class Solution {
public:
    int MOD = 1e9 + 7;

    int lengthAfterTransformations(string s, int t) {
        vector<long long> counts(26, 0);
        for (char ch : s) {
            counts[ch - 'a']++;
        }
        for (int i = 0; i < t; ++i) {
            vector<long long> newCounts(26, 0);
            for (int j = 0; j < 26; ++j) {
                if (j == 25) {
                    newCounts[0] = (newCounts[0] + counts[25]) % MOD;
                    newCounts[1] = (newCounts[1] + counts[25]) % MOD;
                } else {
                    newCounts[j + 1] = (newCounts[j + 1] + counts[j]) % MOD;
                }
            }
            counts = newCounts;
        }
        long long result = 0;
        for (int i = 0; i < 26; ++i) {
            result = (result + counts[i]) % MOD;
        }
        return result;
    }
};
