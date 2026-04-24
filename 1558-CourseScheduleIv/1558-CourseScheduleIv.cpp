// Last updated: 4/24/2026, 10:09:01 PM
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // Step 1: Build adjacency list
        vector<vector<int>> adj(numCourses);
        for (auto& preq : prerequisites) {
            adj[preq[1]].push_back(preq[0]);
        }

        // Step 2: Compute all dependencies using DFS
        vector<unordered_set<int>> allDependencies(numCourses);
        
        function<void(int, unordered_set<int>&)> dfs = [&](int node, unordered_set<int>& visited) {
            for (int neighbor : adj[node]) {
                if (visited.count(neighbor) == 0) {
                    visited.insert(neighbor);
                    dfs(neighbor, visited);
                }
            }
        };

        for (int i = 0; i < numCourses; ++i) {
            dfs(i, allDependencies[i]);
        }

        // Step 3: Answer each query
        vector<bool> result;
        for (auto& query : queries) {
            result.push_back(allDependencies[query[1]].count(query[0]) > 0);
        }

        return result;
    }
};
