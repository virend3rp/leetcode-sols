// Last updated: 5/3/2026, 8:01:29 AM
1class Solution {
2public:
3    bool rotateString(string s, string goal) {
4         return s.length()==goal.length() && (s+s).contains(goal);
5    }
6};