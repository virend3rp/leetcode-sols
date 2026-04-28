// Last updated: 4/28/2026, 7:19:06 PM
1class Solution {
2public:
3    int findContentChildren(vector<int>& g, vector<int>& s) {
4        sort(g.begin(), g.end());
5        sort(s.begin(), s.end());
6        int child = 0, cookie = 0;
7        while (child < g.size() && cookie < s.size()) {
8            if (s[cookie] >= g[child]) child++;  
9            cookie++;    
10        }
11        return child;
12    }
13};