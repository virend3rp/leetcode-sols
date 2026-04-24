// Last updated: 4/24/2026, 10:05:36 PM
class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pre(n + 1, 0);
        vector<long long> suf(n + 1, 0); 
        pre[0] = 0;
        suf[n] = 0;
        long long res = 0;
        long long p = 1;
        p = p << k;
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] | nums[i];
        }
        for (int i = n - 1; i >= 0; i--) {
            suf[i] = suf[i + 1] | nums[i];
        }
        for (int i = 0; i < n; i++) {
            res = max(res, pre[i] | (nums[i] * p) | suf[i + 1]);
        }

        return res;
    }
};