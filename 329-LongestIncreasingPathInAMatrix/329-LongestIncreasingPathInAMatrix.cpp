// Last updated: 4/24/2026, 10:13:35 PM
class Solution {
public:
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j, int n, int m) {
        if (dp[i][j] != -1) return dp[i][j]; // Memoization check
        
        int dx[] = {0, 0, -1, 1};
        int dy[] = {1, -1, 0, 0};
        int maxLength = 1;
        
        for (int k = 0; k < 4; k++) {
            int newX = i + dx[k];
            int newY = j + dy[k];
            
            if (newX >= 0 && newX < n && newY >= 0 && newY < m && matrix[newX][newY] > matrix[i][j]) {
                maxLength = max(maxLength, 1 + dfs(matrix, dp, newX, newY, n, m));
            }
        }
        
        return dp[i][j] = maxLength; // Store the result
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1)); // Memoization table
        int maxPath = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                maxPath = max(maxPath, dfs(matrix, dp, i, j, n, m));
            }
        }
        
        return maxPath;
    }
};
