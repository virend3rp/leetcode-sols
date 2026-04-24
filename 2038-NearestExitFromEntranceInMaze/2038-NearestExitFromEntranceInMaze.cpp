// Last updated: 4/24/2026, 10:07:44 PM
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        queue<pair<pair<int, int>, int>> q;
        q.push({{entrance[0], entrance[1]}, 0});
        maze[entrance[0]][entrance[1]] = '+'; // Mark entrance as visited

        int dx[] = {+1, -1, 0, 0};
        int dy[] = {0, 0, +1, -1};

        while (!q.empty()) {
            auto [pos, steps] = q.front();
            auto [x, y] = pos;
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int newX = x + dx[i];
                int newY = y + dy[i];
                if (newX >= 0 && newY >= 0 && newX < m && newY < n && maze[newX][newY] == '.') {
                    // Check if it's a valid border exit (not entrance)
                    if (newX == 0 || newY == 0 || newX == m - 1 || newY == n - 1) {
                        return steps + 1;
                    }

                    maze[newX][newY] = '+'; // mark as visited
                    q.push({{newX, newY}, steps + 1});
                }
            }
        }

        return -1; // no exit found
    }
};
