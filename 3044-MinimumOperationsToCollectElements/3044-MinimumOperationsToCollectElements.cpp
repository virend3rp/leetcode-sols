// Last updated: 4/24/2026, 10:05:20 PM
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        vector<bool> seen(k + 1, false);
        
        int found = 0;
        int count = 0;

        for (int i = n - 1; i >= 0; i--) {
            int val = nums[i];

            if (val <= k && !seen[val]) {
                seen[val] = true;
                found++;
            }

            count++;

            if (found == k) return count;
        }

        return count;
    }
};