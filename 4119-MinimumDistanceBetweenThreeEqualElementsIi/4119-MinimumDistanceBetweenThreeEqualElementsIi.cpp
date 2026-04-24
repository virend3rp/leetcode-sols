// Last updated: 4/24/2026, 10:03:26 PM
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> indices;
        for (int i = 0; i < nums.size(); i++)
            indices[nums[i]].push_back(i);

        int ans = INT_MAX;
        for (auto& [val, idx] : indices) {
            if (idx.size() < 3) continue;
            for (int i = 0; i + 2 < idx.size(); i++)
                ans = min(ans, 2 * (idx[i+2] - idx[i]));
        }
        return ans == INT_MAX ? -1 : ans;
    }
};