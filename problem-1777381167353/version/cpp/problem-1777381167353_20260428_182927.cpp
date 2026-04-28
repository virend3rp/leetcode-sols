// Last updated: 4/28/2026, 6:29:27 PM
1class Solution {
2public:
3    long long findTheArrayConcVal(vector<int>& nums) {
4        long long result = 0;
5        int l = 0, r = nums.size() - 1;
6        while (l < r) {
7            string concat = to_string(nums[l]) + to_string(nums[r]);
8            result += stoll(concat);
9            l++; r--;
10        }
11        if (l == r) result += nums[l]; // odd length, middle element
12        return result;
13    }
14};