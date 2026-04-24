// Last updated: 4/24/2026, 10:06:24 PM
class Solution {
public:
 vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        // Step 1: Build graphs and indegree arrays for rows and columns
        vector<vector<int>> rowGraph(k + 1), colGraph(k + 1);
        vector<int> rowIndegree(k + 1, 0), colIndegree(k + 1, 0);

        for (auto& cond : rowConditions) {
            rowGraph[cond[0]].push_back(cond[1]);
            rowIndegree[cond[1]]++;
        }
        for (auto& cond : colConditions) {
            colGraph[cond[0]].push_back(cond[1]);
            colIndegree[cond[1]]++;
        }

        // Step 2: Perform topological sort for rows and columns
        vector<int> rowOrder = topologicalSort(rowGraph, rowIndegree, k);
        vector<int> colOrder = topologicalSort(colGraph, colIndegree, k);

        if (rowOrder.empty() || colOrder.empty()) return {}; // Return empty if cycle detected

        // Step 3: Build the matrix
        vector<vector<int>> matrix(k, vector<int>(k, 0));
        vector<int> rowPos(k + 1), colPos(k + 1);

        for (int i = 0; i < k; ++i) {
            rowPos[rowOrder[i]] = i;
            colPos[colOrder[i]] = i;
        }

        for (int i = 1; i <= k; ++i) {
            matrix[rowPos[i]][colPos[i]] = i;
        }

        return matrix;
    }

private:
    vector<int> topologicalSort(const vector<vector<int>>& graph, vector<int>& indegree, int k) {
        queue<int> q;
        vector<int> order;

        for (int i = 1; i <= k; ++i) {
            if (indegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            order.push_back(node);

            for (int neighbor : graph[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) q.push(neighbor);
            }
        }

        return order.size() == k ? order : vector<int>(); // Return empty if not all nodes are sorted
    }
};