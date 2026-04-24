// Last updated: 4/24/2026, 10:09:44 PM
class Solution {
public:
int oddCells(int m, int n, vector<vector<int>>& indices) {
    // Initialize row and column increment counters
    vector<int> row_increments(m, 0);
    vector<int> col_increments(n, 0);
    
    // Apply the increments for each index in indices
    for (const auto& index : indices) {
        row_increments[index[0]]++;
        col_increments[index[1]]++;
    }
    
    // Count the number of rows with odd increments
    int odd_rows = 0;
    for (int count : row_increments) {
        if (count % 2 != 0) {
            odd_rows++;
        }
    }
    
    // Count the number of columns with odd increments
    int odd_cols = 0;
    for (int count : col_increments) {
        if (count % 2 != 0) {
            odd_cols++;
        }
    }
    
    // Calculate the number of rows with even increments
    int even_rows = m - odd_rows;
    // Calculate the number of columns with even increments
    int even_cols = n - odd_cols;
    
    // Calculate the number of odd-valued cells
    int odd_cells = (odd_rows * even_cols) + (even_rows * odd_cols);
    
    // Return the number of odd-valued cells
    return odd_cells;
}
};