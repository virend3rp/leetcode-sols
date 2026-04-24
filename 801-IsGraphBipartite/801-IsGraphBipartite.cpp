// Last updated: 4/24/2026, 10:11:39 PM
class Solution {
public:
    // DFS function to check if the graph is bipartite
    bool dfs(int node, int color, vector<vector<int>>& adjlist, vector<int>& col) {
        col[node] = color;  // Assign the current node a color (0 or 1)
        
        for (auto neighbor : adjlist[node]) {
            if (col[neighbor] == -1) {  // If the neighbor hasn't been colored
                if (!dfs(neighbor, !color, adjlist, col)) {  // Color it with the opposite color
                    return false;
                }
            } else if (col[neighbor] == color) {  // If the neighbor has the same color
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();               // Number of vertices
        vector<int> col(V, -1);             // Color array, initialized to -1 (unvisited)
        
        // Check each component of the graph
        for (int i = 0; i < V; i++) {
            if (col[i] == -1) {  // If the node hasn't been visited
                if (!dfs(i, 0, graph, col)) {  // Start DFS with color 0
                    return false;
                }
            }
        }
        return true;  // If all components are bipartite
    }
};
