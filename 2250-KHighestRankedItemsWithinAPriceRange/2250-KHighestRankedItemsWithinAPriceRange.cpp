// Last updated: 4/24/2026, 10:07:05 PM
class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        priority_queue<array<int, 4> , vector<array<int, 4>>, greater<array<int, 4>>> pq;
        queue<pair<int, int>> q;
        int n = grid.size(), m = grid[0].size();
        q.push({start[0], start[1]});
        auto check = [&](int row, int col) {
            return grid[row][col] >= pricing[0] && grid[row][col] <= pricing[1];
        };

        if(check(start[0], start[1])) {
            pq.push({0, grid[start[0]][start[1]], start[0], start[1]});
        }

        int dx[4] = {0, 0, -1, +1};
        int dy[4] = {-1, +1, 0, 0};
        grid[start[0]][start[1]] = 0;
        int dis = 1;
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                for(int k = 0; k < 4; k++) {
                    int nr = row + dx[k];
                    int nc = col + dy[k];
                    if(nr >= 0 && nc >= 0 && nr < n && nc < m && grid[nr][nc] != 0) {
                        if(check(nr, nc)) {
                            pq.push({dis, grid[nr][nc], nr, nc});
                        }
                        grid[nr][nc] = 0;
                        q.push({nr, nc});
                    }
                }    
            }
            dis++;
        }
        int sz = 0;
        vector<vector<int>> ans;
        while(!pq.empty() && sz < k) {
            ans.push_back({pq.top()[2], pq.top()[3]});
            pq.pop();
            sz++;
        }
        return ans;
    }
};