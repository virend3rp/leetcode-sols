// Last updated: 4/24/2026, 10:05:35 PM
class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int cnt_max = 0;
        int index = 0;

        // Traverse each row:
        for (int i = 0; i < n; i++) {
            int cnt_ones = 0;
            // Count number of 1's in the current row:
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 1) {
                    cnt_ones++;
                }
            }
            // Update if the current row has more 1's:
            if (cnt_ones > cnt_max) {
                cnt_max = cnt_ones;
                index = i;
            }
        }
        return {index, cnt_max};  // Return row index and count of 1's
    }
};
