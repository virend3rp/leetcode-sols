// Last updated: 4/24/2026, 10:11:14 PM
class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n + 1);  // 1-based indexing
    vector<int> color(n + 1, -1);      // -1 means unvisited

    // Build adjacency list
    for (auto& d : dislikes) {
        graph[d[0]].push_back(d[1]);
        graph[d[1]].push_back(d[0]);
    }

    // BFS for each disconnected component
    for (int i = 1; i <= n; ++i) {
        if (color[i] == -1) {
            queue<int> q;
            q.push(i);
            color[i] = 0;  // Assign a group (0 or 1)

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int neighbor : graph[node]) {
                    if (color[neighbor] == -1) {
                        color[neighbor] = 1 - color[node];  // Opposite group
                        q.push(neighbor);
                    } else if (color[neighbor] == color[node]) {
                        return false;  // Conflict found
                    }
                }
            }
        }
    }
    return true;
    }
};