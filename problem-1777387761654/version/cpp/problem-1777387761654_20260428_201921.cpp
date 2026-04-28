// Last updated: 4/28/2026, 8:19:21 PM
1class Solution {
2public:
3int nextValid(string& s, int i) {
4    int skip = 0;
5    while (i >= 0) {
6        if (s[i] == '#') { skip++; i--; }
7        else if (skip > 0) { skip--; i--; }
8        else break;
9    }
10    return i;
11}
12
13bool backspaceCompare(string s, string t) {
14    int i = s.size() - 1;
15    int j = t.size() - 1;
16
17    while (i >= 0 || j >= 0) {
18        i = nextValid(s, i);
19        j = nextValid(t, j);
20
21        if (i >= 0 && j >= 0 && s[i] != t[j]) return false;
22        if ((i >= 0) != (j >= 0)) return false;
23
24        i--; j--;
25    }
26    return true;
27}
28};