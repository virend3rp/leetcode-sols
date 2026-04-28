// Last updated: 4/28/2026, 7:34:00 PM
1class Solution {
2public:
3string reverseVowels(string s) {
4    string vowels = "aeiouAEIOU";
5    int l = 0, r = s.size() - 1;
6    while (l < r) {
7        while (l < r && vowels.find(s[l]) == string::npos) l++;
8        while (l < r && vowels.find(s[r]) == string::npos) r--;
9        if (l < r) swap(s[l++], s[r--]);
10    }
11    return s;
12}
13};