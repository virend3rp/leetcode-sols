// Last updated: 4/24/2026, 10:10:27 PM
class Solution {
public:
int maxDistance(vector<vector<int>>& grid) {
    int n = grid.size();
    queue<pair<int, int>> q;
    
    // Add all land cells to the queue
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                q.push({i, j});
            }
        }
    }

    // If no water or no land, return -1
    if (q.empty() || q.size() == n * n) {
        return -1;
    }

    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int maxDist = -1;

    // BFS from all land cells
    while (!q.empty()) {
        int size = q.size();
        maxDist++;
        
        for (int i = 0; i < size; i++) {
            auto [x, y] = q.front();
            q.pop();

            for (auto [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;
                
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0) {
                    grid[nx][ny] = 1;  // Mark as visited
                    q.push({nx, ny});
                }
            }
        }
    }

    return maxDist;
}
};