// Last updated: 4/28/2026, 6:37:35 PM
1class Solution {
2public:
3    bool isPrefixString(string s, vector<string>& words) {
4        string built = "";
5        for (auto& w : words) {
6            built += w;
7            if (built == s) return true;
8            if (built.size() >= s.size()) return false;
9        }
10        return false;
11    }
12};