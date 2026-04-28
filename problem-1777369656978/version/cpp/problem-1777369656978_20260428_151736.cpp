// Last updated: 4/28/2026, 3:17:36 PM
1class Solution {
2public:
3    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
4        for (auto& row : image) {
5            int start = 0, end = row.size() - 1;
6            while (start < end) {
7                if (row[start] == row[end]) {
8                    row[start] ^= 1;
9                    row[end] ^= 1;
10                }
11                start++; end--;
12            }
13            if (row.size() % 2) row[row.size() / 2] ^= 1;
14        }
15        return image;
16    }
17};