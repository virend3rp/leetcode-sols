// Last updated: 4/28/2026, 3:34:10 PM
1class Solution {
2public:
3    string reverseOnlyLetters(string s) {
4        int l = 0;
5        int r = s.size() - 1;  
6        while (l < r) {
7            if (!isalpha(s[l])) {  
8                l++;
9            } else if (!isalpha(s[r])) { 
10                r--;
11            } else {
12                swap(s[l], s[r]);
13                l++;
14                r--;
15            }
16        }
17        return s;
18    }
19};