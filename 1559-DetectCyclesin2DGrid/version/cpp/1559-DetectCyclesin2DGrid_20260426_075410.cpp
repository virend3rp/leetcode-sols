// Last updated: 4/26/2026, 7:54:10 AM
1class Solution {
2    int m, n;
3    vector<vector<bool>> visited;
4    int dx[4] = {0,0,1,-1};
5    int dy[4] = {1,-1,0,0};
6
7    bool dfs(vector<vector<char>>& grid, int x, int y, int px, int py) {
8        visited[x][y] = true;
9
10        for (int d = 0; d < 4; d++) {
11            int nx = x + dx[d];
12            int ny = y + dy[d];
13
14            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
15            if (grid[nx][ny] != grid[x][y]) continue;
16            if (nx == px && ny == py) continue; 
17            if (visited[nx][ny]) return true; 
18            if (dfs(grid, nx, ny, x, y)) return true;
19        }
20        return false;
21    }
22
23public:
24    bool containsCycle(vector<vector<char>>& grid) {
25        m = grid.size(), n = grid[0].size();
26        visited.assign(m, vector<bool>(n, false));
27
28        for (int i = 0; i < m; i++)
29            for (int j = 0; j < n; j++)
30                if (!visited[i][j])
31                    if (dfs(grid, i, j, -1, -1)) return true;
32
33        return false;
34    }
35};