// Last updated: 4/28/2026, 7:23:48 PM
1class Solution {
2public:
3    bool check(const string& s, int i, int j) {
4        while (i < j) {
5            if (s[i] != s[j]) return false;
6            ++i;
7            --j;
8        }
9        return true;
10    }
11
12    bool validPalindrome(string s) {
13        int i = 0, j = s.size() - 1;
14        while (i < j) {
15            if (s[i] != s[j]) {
16                return check(s, i + 1, j) || check(s, i, j - 1);
17            }
18            ++i;
19            --j;
20        }
21        return true;
22    }
23};
24