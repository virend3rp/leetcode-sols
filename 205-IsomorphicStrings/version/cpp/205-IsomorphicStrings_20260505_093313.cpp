// Last updated: 5/5/2026, 9:33:13 AM
1class Solution {
2public:
3    bool isIsomorphic(string s, string t) {
4        unordered_map<char,char> st, ts;
5        for (int i = 0; i < s.size(); i++) {
6            if (st.count(s[i]) && st[s[i]] != t[i]) return false;
7            if (ts.count(t[i]) && ts[t[i]] != s[i]) return false;
8            st[s[i]] = t[i];
9            ts[t[i]] = s[i];
10        }
11        return true;
12    }
13};