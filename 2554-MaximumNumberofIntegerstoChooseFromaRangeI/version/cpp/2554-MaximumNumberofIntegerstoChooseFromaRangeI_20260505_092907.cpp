// Last updated: 5/5/2026, 9:29:07 AM
1class Solution {
2public:
3    int maxCount(vector<int>& banned, int n, long long maxSum) {
4        unordered_set<int> ban(banned.begin(), banned.end());
5        int count = 0;
6        long long sum = 0;
7        for (int i = 1; i <= n; i++) {
8            if (ban.count(i)) continue;
9            if (sum + i > maxSum) break;
10            sum += i;
11            count++;
12        }
13        return count;
14    }
15};