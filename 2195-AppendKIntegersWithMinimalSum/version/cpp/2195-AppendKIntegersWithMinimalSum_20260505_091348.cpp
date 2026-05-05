// Last updated: 5/5/2026, 9:13:48 AM
1class Solution {
2public:
3    long long minimalKSum(vector<int>& nums, int k) {
4        set<int> s(nums.begin(), nums.end());
5        long long ans = 0, next = 1;
6        for (int num : s) {
7            if (k == 0) break;
8            if (num > next) {
9                long long fill = min((long long)k, (long long)(num - next));
10                ans += (next + next + fill - 1) * fill / 2;
11                k -= fill;
12            }
13            next = num + 1;
14        }
15        if (k > 0) ans += (next + next + k - 1LL) * k / 2;
16        return ans;
17    }
18};