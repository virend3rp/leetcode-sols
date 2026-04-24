// Last updated: 4/24/2026, 10:07:22 PM
class Solution {
public:
    int n;
    long long maxi=-1, count=0;
    int solver(vector<vector<int>>& adj, int node) {
        long long score = 1;
        int childs = adj[node].size();

        int leftNodes = 0, rightNodes = 0;
        if (childs > 0) leftNodes = solver(adj, adj[node][0]);
        if (childs > 1) rightNodes = solver(adj, adj[node][1]);

        if (leftNodes > 0) score *=leftNodes;
        if (rightNodes > 0) score *=rightNodes;

        int parentNodes = n-leftNodes-rightNodes-1;
        if (parentNodes > 0) score *= parentNodes;

        if (score > maxi) {
            maxi = score;
            count = 1;
        }

        else if (score == maxi) count++;

        return leftNodes + rightNodes + 1;
    }
    int countHighestScoreNodes(vector<int>& parents) {
        n = parents.size();
        vector<vector<int>> adj(n);
        for (int i=1; i<n; i++) {
            adj[parents[i]].push_back(i);
        }

        solver(adj, 0);
        return count;
    }
};