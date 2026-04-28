// Last updated: 4/28/2026, 12:38:22 PM
1class Solution {
2public:
3    int minOperations(vector<vector<int>>& grid, int x) {
4        int m = grid.size(), n = grid[0].size();
5        int tn = m * n, tc = 0;
6        int a[tn];
7        for (int i = 0; i < m; i++)
8            for (int j = 0; j < n; j++)
9                a[i * n + j] = grid[i][j];
10        sort(a, a + tn);
11        int mid = tn / 2;
12        for (int i = 0; i < tn; i++) {
13            if ((abs(a[i] - a[mid])) % x != 0)
14                return -1;
15            tc += abs(a[i] - a[mid]) / x;
16        }
17        return tc;
18    }
19};
20        