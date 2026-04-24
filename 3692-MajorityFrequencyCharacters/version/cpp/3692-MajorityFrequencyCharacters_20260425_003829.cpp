// Last updated: 4/25/2026, 12:38:29 AM
1class Solution {
2public:
3string majorityFrequencyGroup(string s) {
4    unordered_map<char, int> freq;
5    for (char c : s) freq[c]++;
6
7    map<int, vector<char>> groups;
8    for (auto& [c, f] : freq) groups[f].push_back(c);
9
10    int bestK = -1, bestSize = -1;
11    for (auto& [k, chars] : groups) {
12        int sz = chars.size();
13        if (sz > bestSize || (sz == bestSize && k > bestK)) {
14            bestSize = sz;
15            bestK = k;
16        }
17    }
18
19    string ans(groups[bestK].begin(), groups[bestK].end());
20    return ans;
21}
22};