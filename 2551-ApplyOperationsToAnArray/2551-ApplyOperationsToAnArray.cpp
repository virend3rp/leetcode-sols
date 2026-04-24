// Last updated: 4/24/2026, 10:06:06 PM
class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Apply the doubling operation
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }

        // Step 2: Shift non-zero elements to the left
        int index = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                nums[index++] = nums[i];
            }
        }

        // Step 3: Fill the remaining elements with zeros
        while (index < n) {
            nums[index++] = 0;
        }

        return nums;
    }
};
