// Last updated: 4/24/2026, 10:15:41 PM
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> final = {{1}};
        if (numRows == 1) return final;

        final.push_back({1, 1});

        for (int i = 2; i < numRows; i++) {
            vector<int> temp = {1};
            for (int j = 1; j < i; j++) {
                temp.push_back(final[i-1][j-1] + final[i-1][j]);
            }
            temp.push_back(1);
            final.push_back(temp); // was missing
        }

        return final;
    }
};