// Last updated: 4/25/2026, 12:45:46 AM
1class Solution {
2public:
3bool isCircularSentence(string sentence) {
4    int n = sentence.size();
5    if (sentence[0] != sentence[n-1]) return false;
6    for (int i = 1; i < n - 1; i++) {
7        if (sentence[i] == ' ') {
8            if (sentence[i-1] != sentence[i+1]) return false;
9        }
10    }
11    return true;
12}
13};