// Last updated: 4/29/2026, 5:39:19 PM
1class Solution {
2public:
3vector<int> sortArrayByParity(vector<int>& nums) {
4    int l = 0, r = nums.size() - 1;
5    while (l < r) {
6        if (nums[l] % 2 > nums[r] % 2)
7            swap(nums[l], nums[r]);
8        if (nums[l] % 2 == 0) l++;
9        if (nums[r] % 2 == 1) r--;
10    }
11    return nums;
12}
13};