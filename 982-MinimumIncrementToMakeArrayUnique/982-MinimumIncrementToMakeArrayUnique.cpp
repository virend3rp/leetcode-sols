// Last updated: 4/24/2026, 10:10:58 PM
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        // Sort the array
        sort(nums.begin(), nums.end());
        
        int count = 0;
        int nextAvailable = -1; // To track the next available unique number
        
        // Traverse the sorted array
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] <= nextAvailable) {
                // If the current number is less than or equal to the next available unique number
                count += (nextAvailable + 1 - nums[i]); // Increment to nextAvailable
                nextAvailable++; // Update nextAvailable
            } else {
                // If the current number is already greater than nextAvailable
                nextAvailable = nums[i]; // No increment needed, just update nextAvailable
            }
        }
        
        return count;
    }
};
