// Last updated: 4/24/2026, 10:03:50 PM

class Spreadsheet {
private:
    vector<vector<int>> grid;

public:
    Spreadsheet(int rows) {
        grid.resize(rows, vector<int>(26, 0));
    }
    void setCell(string cell, int value) {
        int col = cell[0] - 'A'; 
        int row = stoi(cell.substr(1)) - 1;
        grid[row][col] = value;
    }

    void resetCell(string cell) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;
        grid[row][col] = 0; 
    }

    int getValue(string formula) {
        if (formula[0] == '=') formula = formula.substr(1);

        int sum = 0;
        int i = 0, n = formula.size();

        while (i < n) {
            string part;
            while (i < n && formula[i] != '+') {
                part += formula[i++];
            }
            i++; 
            if (isalpha(part[0])) {
                int col = part[0] - 'A';
                string rowStr = part.substr(1);

                if (!rowStr.empty() && all_of(rowStr.begin(), rowStr.end(), ::isdigit)) {
                    int row = stoi(rowStr) - 1;
                    sum += grid[row][col];
                } else {
                    throw invalid_argument("Invalid cell reference: " + part);
                }
            } else { 
                sum += stoi(part);
            }
        }

        return sum;
    }
};