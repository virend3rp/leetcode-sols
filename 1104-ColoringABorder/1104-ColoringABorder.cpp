// Last updated: 4/24/2026, 10:10:30 PM
class Solution {
public:
    int n, m;
    vector<vector<int>> ans;
    vector<vector<bool>> visited;

    void dfs(vector<vector<int>>& grid, int row, int col, int inicolor, int newColor) {
        visited[row][col] = true;

        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};

        bool isBorder = false;

        for (int i = 0; i < 4; i++) {
            int newRow = row + dx[i];
            int newCol = col + dy[i];

            if (newRow < 0 || newCol < 0 || newRow >= n || newCol >= m) {
                isBorder = true;  // Edge of grid
                continue;
            }

            if (grid[newRow][newCol] != inicolor) {
                isBorder = true;  // Different color neighbor
            } else if (!visited[newRow][newCol]) {
                dfs(grid, newRow, newCol, inicolor, newColor);
            }
        }

        if (isBorder) {
            ans[row][col] = newColor;  // Only color border cells
        }
    }

    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        n = grid.size();
        m = grid[0].size();
        ans = grid;
        visited = vector<vector<bool>>(n, vector<bool>(m, false));

        int inicolor = grid[row][col];
        dfs(grid, row, col, inicolor, color);

        return ans;
    }
};
