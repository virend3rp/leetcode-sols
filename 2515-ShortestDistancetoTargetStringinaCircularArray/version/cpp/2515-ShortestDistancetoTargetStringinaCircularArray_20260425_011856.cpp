// Last updated: 4/25/2026, 1:18:56 AM
1class Solution {
2public:
3int closestTarget(vector<string>& words, string target, int startIndex) {
4    int n = words.size();
5    int result = INT_MAX;
6
7    for (int i = 0; i < n; i++) {
8        if (words[i] == target) {
9            int straight = abs(startIndex - i);
10            int circular = n - straight;
11            result = min(result, min(straight, circular));
12        }
13    }
14    return result == INT_MAX ? -1 : result;
15}
16};