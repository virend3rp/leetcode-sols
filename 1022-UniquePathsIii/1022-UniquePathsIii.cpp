// Last updated: 4/24/2026, 10:10:52 PM
class Solution {
public:
    void solve(vector<vector<int>>& grid, int m, int n, int x, int y, int remaining, int &count) {
        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == -1) {
            return;
        }
        if (grid[x][y] == 2) {
            if (remaining == 0) { // All non-obstacle cells visited
                count++;
            }
            return;
        }
        int temp = grid[x][y];
        grid[x][y] = -1;

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        for (int i = 0; i < 4; ++i) {
            solve(grid, m, n, x + dx[i], y + dy[i], remaining - 1, count);
        }
        // Backtrack and unmark the cell
        grid[x][y] = temp;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int count = 0;
        int startX = 0, startY = 0, nonObstacles = 0;
        int m = grid.size();
        int n = grid[0].size();

        // Find the start point and count non-obstacle cells
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    startX = i;
                    startY = j;
                }
                if (grid[i][j] != -1) { // Count all non-obstacle cells
                    nonObstacles++;
                }
            }
        }
        solve(grid, m, n, startX, startY, nonObstacles - 1, count);
        return count;
    }
};
