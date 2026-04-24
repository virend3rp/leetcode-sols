// Last updated: 4/24/2026, 10:14:39 PM
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if (n == 0) return 0; // Edge case: empty grid
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int count = 0;

        // Helper function for BFS
        auto bfs = [&](int x, int y) {
            queue<pair<int, int>> q;
            q.push({x, y});
            visited[x][y] = true;

            // Directions for moving up, down, left, and right
            vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
            while (!q.empty()) {
                auto [curX, curY] = q.front();
                q.pop();

                for (auto [dx, dy] : directions) {
                    int newX = curX + dx;
                    int newY = curY + dy;

                    if (newX >= 0 && newX < n && newY >= 0 && newY < m &&
                        grid[newX][newY] == '1' && !visited[newX][newY]) {
                        visited[newX][newY] = true;
                        q.push({newX, newY});
                    }
                }
            }
        };

        // Traverse the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    count++;
                    bfs(i, j); // Start BFS to mark the entire island
                }
            }
        }

        return count;
    }
};
