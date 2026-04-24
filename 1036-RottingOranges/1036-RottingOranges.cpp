// Last updated: 4/24/2026, 10:10:48 PM
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(); // Number of rows
        int m = grid[0].size(); // Number of columns
        queue<pair<pair<int, int>, int>> q; // Queue to store (row, col, time)
        vector<vector<int>> vis(n, vector<int>(m, 0)); // Visited matrix
        int cntfresh = 0; // Count of fresh oranges

        // Initialize the queue with all rotten oranges and count fresh oranges
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2; // Mark as visited (rotten)
                }
                if (grid[i][j] == 1) {
                    cntfresh++; // Count fresh oranges
                }
            }
        }

        int tm = 0; // Time to rot all oranges
        int drow[] = {-1, 0, +1, 0}; // Row direction vectors
        int dcol[] = {0, 1, 0, -1}; // Column direction vectors
        int cnt = 0; // Count of rotten oranges processed

        // Perform BFS to rot all reachable oranges
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();

            tm = max(tm, t); // Update maximum time

            for (int i = 0; i < 4; ++i) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1) {
                    q.push({{nrow, ncol}, t + 1});
                    vis[nrow][ncol] = 2; // Mark as visited (rotten)
                    cnt++;
                }
            }
        }

        if (cnt != cntfresh) {
            return -1; // Not all fresh oranges could rot
        }
        return tm; // Return the time taken to rot all oranges
    }
};