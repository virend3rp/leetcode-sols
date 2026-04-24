// Last updated: 4/24/2026, 10:08:24 PM
class Solution {
public:
int maximumUniqueSubarray(vector<int>& nums) {
    unordered_map<int, int> lastSeen; 
    int left = 0, maxSum = 0, currSum = 0;

    for (int right = 0; right < nums.size(); right++) {
        if (lastSeen.count(nums[right]) && lastSeen[nums[right]] >= left) {
            while (left <= lastSeen[nums[right]]) {
                currSum -= nums[left];
                left++;
            }
        }

        currSum += nums[right];
        maxSum = max(maxSum, currSum);
        lastSeen[nums[right]] = right;
    }

    return maxSum;
}
};