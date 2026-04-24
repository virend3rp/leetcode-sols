// Last updated: 4/25/2026, 1:03:40 AM
1class Solution {
2public:
3    vector<int> decrypt(vector<int>& code, int k) {
4        int n = code.size();
5        vector<int> ans(n, 0);
6        if (k == 0) return ans;
7
8        int l, r, windowSum = 0;
9        if (k > 0) { l = 1;     r = k; }
10        else        { l = n + k; r = n - 1; }
11        for (int i = l; i <= r; i++)
12            windowSum += code[i % n];
13
14        for (int i = 0; i < n; i++) {
15            ans[i] = windowSum;
16            windowSum += code[(r + 1) % n];
17            windowSum -= code[l % n];
18            l++; r++;
19        }
20        return ans;
21    }
22};