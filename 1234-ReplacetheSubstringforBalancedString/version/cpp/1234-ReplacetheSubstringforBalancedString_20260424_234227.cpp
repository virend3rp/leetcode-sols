// Last updated: 4/24/2026, 11:42:27 PM
1class Solution {
2public:
3bool valid(unordered_map<char, int>& total, unordered_map<char, int>& win, int k) {
4    return total['Q'] - win['Q'] <= k &&
5           total['W'] - win['W'] <= k &&
6           total['E'] - win['E'] <= k &&
7           total['R'] - win['R'] <= k;
8}
9
10int balancedString(string s) {
11    int n = s.size(), k = n / 4;
12    unordered_map<char, int> total, win;
13
14    for (char c : s) total[c]++;
15
16    if (total['Q'] == k && total['W'] == k &&
17        total['E'] == k && total['R'] == k) return 0;
18
19    int ans = n, l = 0;
20    for (int r = 0; r < n; r++) {
21        win[s[r]]++;
22        while (valid(total, win, k)) {
23            ans = min(ans, r - l + 1);
24            win[s[l]]--;
25            l++;
26        }
27    }
28    return ans;
29}
30};