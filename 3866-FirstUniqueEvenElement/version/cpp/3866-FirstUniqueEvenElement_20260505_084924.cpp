// Last updated: 5/5/2026, 8:49:24 AM
1class Solution {
2public:
3    int firstUniqueEven(vector<int>& nums) {
4        unordered_map<int,int> freq;
5        for (int n : nums) freq[n]++;
6        for (int n : nums)
7            if (n % 2 == 0 && freq[n] == 1) return n;
8        return -1;
9    }
10};