// Last updated: 4/24/2026, 10:13:43 PM
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0}; // Special case: single node
        
        // Step 1: Build the adjacency list
        vector<vector<int>> adj(n);
        vector<int> degree(n, 0); // Track the degree of each node
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }
        
        // Step 2: Initialize the first layer of leaves
        queue<int> leaves;
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 1) {
                leaves.push(i);
            }
        }
        
        // Step 3: Trim the leaves until we reach the core (1 or 2 nodes)
        while (n > 2) {
            int leavesCount = leaves.size();
            n -= leavesCount; // Remove the current layer of leaves
            
            for (int i = 0; i < leavesCount; ++i) {
                int leaf = leaves.front();
                leaves.pop();
                
                // Remove the leaf from the graph
                for (int neighbor : adj[leaf]) {
                    degree[neighbor]--;
                    if (degree[neighbor] == 1) { // If it becomes a leaf, add it to the queue
                        leaves.push(neighbor);
                    }
                }
            }
        }
        
        // Step 4: The remaining nodes are the roots of the MHTs
        vector<int> result;
        while (!leaves.empty()) {
            result.push_back(leaves.front());
            leaves.pop();
        }
        
        return result;
    }
};