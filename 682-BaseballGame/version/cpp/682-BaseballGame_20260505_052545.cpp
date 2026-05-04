// Last updated: 5/5/2026, 5:25:45 AM
1class Solution {
2public:
3    int calPoints(vector<string>& ops) {
4        vector<int> stk;
5        for (auto& op : ops) {
6            if (op == "+") stk.push_back(stk.back() + stk[stk.size()-2]);
7            else if (op == "D") stk.push_back(stk.back() * 2);
8            else if (op == "C") stk.pop_back();
9            else stk.push_back(stoi(op));
10        }
11        return accumulate(stk.begin(), stk.end(), 0);
12    }
13};