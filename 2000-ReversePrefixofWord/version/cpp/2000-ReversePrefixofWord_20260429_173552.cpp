// Last updated: 4/29/2026, 5:35:52 PM
1class Solution {
2public:
3    string reversePrefix(string word, char ch) {
4        int i = word.find(ch);
5        if (i != string::npos)
6            reverse(word.begin(), word.begin() + i + 1);
7        return word;
8    }
9};