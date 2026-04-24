// Last updated: 4/24/2026, 10:17:31 PM
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        vector<string> rows(min(numRows, int(s.length())));
        int currentRow = 0;
        bool goingDown = false;

        // Loop through all characters in the string
        for (char c : s) {
            rows[currentRow] += c;

            // Change direction when we reach the top or bottom row
            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown;
            }

            // Move to the next row
            currentRow += goingDown ? 1 : -1;
        }

        // Join all rows into the final result
        string result;
        for (const string& row : rows) {
            result += row;
        }

        return result;
    }
};