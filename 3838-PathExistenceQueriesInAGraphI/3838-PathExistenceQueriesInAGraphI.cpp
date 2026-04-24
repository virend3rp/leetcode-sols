// Last updated: 4/24/2026, 10:03:45 PM
class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px != py)
            parent[px] = py;
    }

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        parent.resize(n);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
        for (int i = 1; i < n; ++i) {
            if (nums[i] - nums[i - 1] <= maxDiff) {
                unite(i, i - 1);
            }
        }
        vector<bool> res;
        for (auto& q : queries) {
            res.push_back(find(q[0]) == find(q[1]));
        }
        return res;
    }
};
