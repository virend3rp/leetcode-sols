// Last updated: 4/28/2026, 7:39:30 PM
1class Solution {
2public:
3string reverseWords(string s) {
4    int l = 0;
5    for (int r = 0; r <= s.size(); r++) {
6        if (r == s.size() || s[r] == ' ') {
7            reverse(s.begin() + l, s.begin() + r);
8            l = r + 1;
9        }
10    }
11    return s;
12}
13};