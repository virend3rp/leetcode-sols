// Last updated: 4/28/2026, 6:55:38 PM
1class Solution {
2public:
3    string mergeAlternately(string word1, string word2) {
4        string result = "";
5        int i = 0, j = 0;
6        while (i < word1.size() && j < word2.size()) {
7            result += word1[i++];
8            result += word2[j++];
9        }
10        while (i < word1.size()) result += word1[i++];
11        while (j < word2.size()) result += word2[j++];
12        return result;
13    }
14};