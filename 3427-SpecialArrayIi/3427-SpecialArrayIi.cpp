// Last updated: 4/24/2026, 10:04:45 PM
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> breaks(n - 1, 0);
        for (int i = 0; i < n - 1; ++i) {
            if ((nums[i] % 2) == (nums[i + 1] % 2)) {
                breaks[i] = 1;
            }
        }
        vector<int> prefix(n, 0);
        for (int i = 0; i < n - 1; ++i) {
            prefix[i + 1] = prefix[i] + breaks[i];
        }
        vector<bool> result;
        for (auto& q : queries) {
            int l = q[0];
            int r = q[1];
            result.push_back(prefix[r] - prefix[l] == 0);
        }

        return result;
    }
};
