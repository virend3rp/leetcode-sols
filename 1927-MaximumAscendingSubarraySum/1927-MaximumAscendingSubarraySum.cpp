// Last updated: 4/24/2026, 10:07:59 PM
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        // Initialize the current sum and maximum sum with the first element
        int currentSum = nums[0];
        int maxSum = currentSum;
        
        // Iterate through the array starting from the second element
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) { // Extend ascending subarray
                currentSum += nums[i];
            } else { // Start a new subarray
                currentSum = nums[i];
            }
            // Update maxSum if currentSum is greater
            maxSum = max(maxSum, currentSum);
        }
        
        return maxSum; // Return the maximum sum of an ascending subarray
    }
};
