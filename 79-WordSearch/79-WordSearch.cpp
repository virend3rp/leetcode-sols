// Last updated: 4/24/2026, 10:16:15 PM
class Solution {
public:
    int m, n;
    string word;
    vector<vector<char>> board;
    bool backtrack(int i, int j, int k) {
        if (k == word.length()) return true;

        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[k]) {
            return false;
        }

        char temp = board[i][j];
        board[i][j] = '\0';  // Mark as visited

        bool found = backtrack(i + 1, j, k + 1) ||
                     backtrack(i - 1, j, k + 1) ||
                     backtrack(i, j + 1, k + 1) ||
                     backtrack(i, j - 1, k + 1);

        board[i][j] = temp;  // Restore cell after backtracking
        return found;
    }
    bool exist(vector<vector<char>>& inputBoard, string inputWord) {
        board = inputBoard;
        word = inputWord;
        m = board.size();
        n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (backtrack(i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};
