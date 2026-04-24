// Last updated: 4/24/2026, 10:09:28 PM

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        // If there are fewer connections than n - 1, it's impossible to connect all computers
        if (connections.size() < n - 1) {
            return -1;
        }
        
        // Initialize Union-Find data structure
        vector<int> parent(n);
        vector<int> rank(n, 0);
        iota(parent.begin(), parent.end(), 0); // Fill parent with 0, 1, ..., n-1
        
        // Find function with path compression
        function<int(int)> find = [&](int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        };
        
        // Union function with union by rank
        auto unionNodes = [&](int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX != rootY) {
                if (rank[rootX] > rank[rootY]) {
                    parent[rootY] = rootX;
                } else if (rank[rootX] < rank[rootY]) {
                    parent[rootX] = rootY;
                } else {
                    parent[rootY] = rootX;
                    rank[rootX]++;
                }
                return true;
            }
            return false;
        };
        
        // Count redundant connections
        int redundant = 0;
        for (const auto& connection : connections) {
            if (!unionNodes(connection[0], connection[1])) {
                redundant++;
            }
        }
        
        // Count the number of connected components
        int components = 0;
        for (int i = 0; i < n; ++i) {
            if (find(i) == i) {
                components++;
            }
        }
        
        // To connect all components, we need at least (components - 1) additional connections
        if (redundant >= components - 1) {
            return components - 1;
        }
        return -1;
    }
};