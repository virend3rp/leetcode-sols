// Last updated: 4/28/2026, 6:36:16 PM
1class Solution {
2public:
3    int countPrefixes(vector<string>& words, string s) {
4        int count = 0;
5        for (auto& w : words) {
6            if (s.find(w) == 0) count++;
7        }
8        return count;
9    }
10};