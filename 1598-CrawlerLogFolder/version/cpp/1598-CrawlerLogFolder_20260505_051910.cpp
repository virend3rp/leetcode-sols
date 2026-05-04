// Last updated: 5/5/2026, 5:19:10 AM
1class Solution {
2public:
3    int minOperations(vector<string>& logs) {
4        int depth = 0;
5        for (auto& op : logs) {
6            if (op == "../") depth = max(0, depth - 1);
7            else if (op == "./") continue;
8            else depth++;
9        }
10        return depth;
11    }
12};