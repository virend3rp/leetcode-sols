// Last updated: 4/24/2026, 10:10:57 PM
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        unordered_map<int, vector<int>> rowMap, colMap;
        for (int i = 0; i < stones.size(); ++i) {
                rowMap[stones[i][0]].push_back(i); // Map row to stone indices
                colMap[stones[i][1]].push_back(i); // Map column to stone indices
        }
        // Visited array to track visited stones
        vector<bool> visited(stones.size(), false);
        int components = 0;
        // Helper function for DFS
        function<void(int)> dfs = [&](int node) {
            visited[node] = true;
            // Traverse all stones in the same row
            for (int neighbor : rowMap[stones[node][0]]) {
                if (!visited[neighbor]) {
                    dfs(neighbor);
                }
            }
            // Traverse all stones in the same column
            for (int neighbor : colMap[stones[node][1]]) {
                if (!visited[neighbor]) {
                    dfs(neighbor);
                }
            }
        };

        // Perform DFS for each unvisited stone
        for (int i = 0; i < stones.size(); ++i) {
            if (!visited[i]) {
                components++;
                dfs(i); // Start a new DFS traversal
            }
        }

        // The number of stones that can be removed is total stones - components
        return stones.size() - components;
    }
};