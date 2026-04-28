// Last updated: 4/28/2026, 7:57:00 PM
1class Solution {
2public:
3vector<int> sortedSquares(vector<int>& nums) {
4    int l = 0, r = nums.size() - 1;
5    vector<int> result(nums.size());
6    int pos = nums.size() - 1;
7    
8    while (l <= r) {
9        int lsq = nums[l] * nums[l];
10        int rsq = nums[r] * nums[r];
11        if (lsq > rsq) { result[pos--] = lsq; l++; }
12        else            { result[pos--] = rsq; r--; }
13    }
14    return result;
15}
16};