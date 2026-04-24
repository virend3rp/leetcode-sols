// Last updated: 4/24/2026, 10:16:33 PM
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // Initialize an n x n matrix filled with zeros
        vector<vector<int>> grid(n, vector<int>(n, 0));

        int count = 1;
        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;

        while (top <= bottom && left <= right) {
            // Fill the top row (left to right)
            for (int i = left; i <= right; i++) {
                grid[top][i] = count++;
            }
            top++;

            // Fill the right column (top to bottom)
            for (int i = top; i <= bottom; i++) {
                grid[i][right] = count++;
            }
            right--;

            // Fill the bottom row (right to left)
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    grid[bottom][i] = count++;
                }
                bottom--;
            }

            // Fill the left column (bottom to top)
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    grid[i][left] = count++;
                }
                left++;
            }
        }

        return grid;
    }
};