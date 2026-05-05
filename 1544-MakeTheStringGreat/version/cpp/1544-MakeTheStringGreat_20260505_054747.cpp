// Last updated: 5/5/2026, 5:47:47 AM
1class Solution {
2public:
3    string makeGood(string s) {
4        string stk;
5        for (char c : s) {
6            if (!stk.empty() && abs(stk.back() - c) == 32)
7                stk.pop_back();
8            else
9                stk.push_back(c);
10        }
11        return stk;
12    }
13};