// Last updated: 4/28/2026, 7:51:05 PM
1class Solution {
2public:
3    int countBinarySubstrings(string s) {
4        int prev = 0, curr = 1, result = 0;
5        for (int i = 1; i < s.size(); i++) {
6            if (s[i] == s[i-1]) curr++;
7            else {
8                result += min(prev, curr);
9                prev = curr;
10                curr = 1;
11            }
12        }
13        return result + min(prev, curr);
14    }
15};