// Last updated: 4/25/2026, 1:45:04 AM
1class Solution {
2public:
3bool valid(int total[], int win[], int k) {
4    return total[0] - win[0] >= k &&
5           total[1] - win[1] >= k &&
6           total[2] - win[2] >= k;
7}
8
9int takeCharacters(string s, int k) {
10    int n = s.size();
11    int total[3] = {0}, win[3] = {0};
12
13    for (char c : s) total[c - 'a']++;
14
15    if (total[0] < k || total[1] < k || total[2] < k) return -1;
16    if (k == 0) return 0;
17
18    int maxWin = 0, l = 0;
19    for (int r = 0; r < n; r++) {
20        win[s[r] - 'a']++;
21        while (!valid(total, win, k)) {
22            win[s[l] - 'a']--;
23            l++;
24        }
25        maxWin = max(maxWin, r - l + 1);
26    }
27    return n - maxWin;
28}
29};