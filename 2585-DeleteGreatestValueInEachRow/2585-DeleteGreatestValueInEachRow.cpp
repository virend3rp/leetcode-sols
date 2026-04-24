// Last updated: 4/24/2026, 10:05:59 PM
class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        // Step 1: Sort each row
        for (auto& row : grid) {
            sort(row.begin(), row.end());
        }

        int m = grid.size();        // number of rows
        int n = grid[0].size();     // number of columns
        int ans = 0;

        // Step 2: Traverse column-wise from right to left
        for (int col = n - 1; col >= 0; --col) {
            int maxVal = 0;
            for (int row = 0; row < m; ++row) {
                maxVal = max(maxVal, grid[row][col]);
            }
            ans += maxVal;
        }

        return ans;
    }
};
