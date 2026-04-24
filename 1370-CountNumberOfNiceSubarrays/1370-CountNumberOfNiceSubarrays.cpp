// Last updated: 4/24/2026, 10:09:45 PM
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        freq[0] = 1;
        int prefix = 0, ans = 0;
        for (int x : nums) {
            prefix += (x % 2 != 0 ? 1 : 0);
            ans += freq.count(prefix - k) ? freq[prefix - k] : 0;
            freq[prefix]++;
        }
        return ans;
    }
};