// Last updated: 4/24/2026, 10:03:53 PM
class Solution {
public:
    int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
        const int n = original.size();
        const int MOD = 1e9 + 7;
        long long minVal = bounds[0][0];
        long long maxVal = bounds[0][1];  
        for (int i = 1; i < n; i++) {
            long long diff = original[i] - original[0];
            long long minRequired = bounds[i][0] - diff;
            long long maxAllowed = bounds[i][1] - diff;
            minVal = max(minVal, minRequired);
            maxVal = min(maxVal, maxAllowed);
        }
        if (maxVal < minVal) return 0;
        return (int)((maxVal - minVal + 1) % MOD);
    }
};