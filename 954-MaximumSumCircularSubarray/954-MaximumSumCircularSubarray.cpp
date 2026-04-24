// Last updated: 4/24/2026, 10:11:03 PM
class Solution {
public:
int maxSubarraySumCircular(vector<int>& nums) {
    int totalSum = 0;
    int curMax = 0, maxSum = nums[0];
    int curMin = 0, minSum = nums[0];

    for (int x : nums) {
        curMax = max(curMax + x, x);
        maxSum = max(maxSum, curMax);

        curMin = min(curMin + x, x);
        minSum = min(minSum, curMin);

        totalSum += x;
    }

    return maxSum > 0 ? max(maxSum, totalSum - minSum) : maxSum;
}
};