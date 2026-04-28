// Last updated: 4/28/2026, 6:51:19 PM
1class Solution {
2public:
3    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
4        int minIdx = 0, maxIdx = 0;
5        for (int j = indexDifference; j < nums.size(); j++) {
6            int i = j - indexDifference;
7            if (nums[i] < nums[minIdx]) minIdx = i;
8            if (nums[i] > nums[maxIdx]) maxIdx = i;
9            if (nums[j] - nums[minIdx] >= valueDifference) return {minIdx, j};
10            if (nums[maxIdx] - nums[j] >= valueDifference) return {maxIdx, j};
11        }
12        return {-1, -1};
13    }
14};