// Last updated: 5/5/2026, 5:59:39 AM
1class Solution {
2public:
3    int countStudents(vector<int>& students, vector<int>& sandwiches) {
4        int cnt[2] = {0, 0};
5        for (int s : students) cnt[s]++;
6
7        for (int s : sandwiches) {
8            if (cnt[s] == 0) return cnt[0] + cnt[1];
9            cnt[s]--;
10        }
11        return 0;
12    }
13};