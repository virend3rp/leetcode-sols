// Last updated: 4/24/2026, 10:03:36 PM
class Solution {
public:
    int n;
    vector<vector<pair<int, int>>> adj;
    void dfs(int node, int par, vector<int>& vis, int mid) {
        vis[node] = true;
        for (auto& [neigh, w] : adj[node]) {
            if (neigh == par || vis[neigh]) continue;
            if (w > mid) 
                dfs(neigh, node, vis, mid);
        }
    }

    bool check(int mid, int k) {
        vector<int> vis(n, false);
        int comp = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, -1, vis, mid);
                comp++;
                if (comp >= k)
                    return true;
            }
        }
        return false;
    }

    int minTime(int n, vector<vector<int>>& edges, int k) {
        this->n = n;
        adj.resize(n);

        for (auto& E : edges) {
            int u = E[0], v = E[1], w = E[2];
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }

        int l = 0, h = 1e9;
        int ans = h;

        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (check(mid, k)) {
                ans = mid;
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};