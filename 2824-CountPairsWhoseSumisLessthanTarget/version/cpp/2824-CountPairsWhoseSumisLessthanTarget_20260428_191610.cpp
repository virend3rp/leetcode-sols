// Last updated: 4/28/2026, 7:16:10 PM
1class Solution {
2public:
3int countPairs(vector<int>& nums, int target) {
4    sort(nums.begin(), nums.end());
5    int left = 0, right = nums.size() - 1, count = 0;
6    while (left < right) {
7        if (nums[left] + nums[right] < target) {
8            count += right - left;  
9            left++;
10        } else {
11            right--;
12        }
13    }
14    return count;
15}
16};