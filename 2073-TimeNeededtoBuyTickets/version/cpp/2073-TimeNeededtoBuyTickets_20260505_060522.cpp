// Last updated: 5/5/2026, 6:05:22 AM
1class Solution {
2public:
3    int timeRequiredToBuy(vector<int>& tickets, int k) {
4        int time = 0;
5        for (int i = 0; i < tickets.size(); i++) {
6            if (i <= k) time += min(tickets[i], tickets[k]);
7            else        time += min(tickets[i], tickets[k] - 1);
8        }
9        return time;
10    }
11};