// Last updated: 4/24/2026, 10:07:30 PM
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (original.size() != m * n) return {};

        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = 0; i < original.size(); i++)
            ans[i / n][i % n] = original[i];

        return ans;
    }
};