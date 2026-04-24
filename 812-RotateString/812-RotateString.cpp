// Last updated: 4/24/2026, 10:11:36 PM
class Solution {
public:
    bool rotateString(string s, string goal) {
         return s.length()==goal.length() && (s+s).contains(goal);
    }
};