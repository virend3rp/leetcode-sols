// Last updated: 4/28/2026, 6:32:31 PM
1class Solution {
2public:
3    int isPrefixOfWord(string sentence, string searchWord) {
4        istringstream ss(sentence);
5        string word;
6        int idx = 1;
7        while (ss >> word) {
8            if (word.find(searchWord) == 0) return idx;
9            idx++;
10        }
11        return -1;
12    }
13};