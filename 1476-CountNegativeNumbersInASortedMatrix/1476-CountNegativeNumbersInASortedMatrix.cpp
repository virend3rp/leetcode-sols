// Last updated: 4/24/2026, 10:09:20 PM
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int i = n - 1;  // start from last row
        int j = 0;      // start from first column
        int count = 0;

        while (i >= 0 && j < m) {
            if (grid[i][j] < 0) {
                count += (m - j);
                i--;  // move up
            } else {
                j++;  // move right
            }
        }

        return count;
    }
};
