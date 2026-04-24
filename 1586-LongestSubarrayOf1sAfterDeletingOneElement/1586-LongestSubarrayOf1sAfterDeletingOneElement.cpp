// Last updated: 4/24/2026, 10:08:57 PM
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0, r = 0;
        int zeroCount = 0;
        int ans = 0;

        while (r < nums.size()) {
            if (nums[r] == 0) zeroCount++;

            while (zeroCount > 1) {
                if (nums[l] == 0) zeroCount--;
                l++;
            }

            ans = max(ans, r - l);
            r++;
        }

        return ans;
    }
};
