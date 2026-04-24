// Last updated: 4/24/2026, 10:05:28 PM
class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> mpp;
        for (int i = 0; i < nums.size(); i++) {
            mpp[nums[i]].push_back(i);
        }
        int maxi = 0;
        for (auto& [val, pos] : mpp) {
            int l = 0;
            for (int r = 0; r < pos.size(); r++) {
                while ((pos[r] - pos[l] + 1) - (r - l + 1) > k) {
                    l++;
                }
                maxi = max(maxi, r - l + 1);
            }
        }
        return maxi;
    }
};