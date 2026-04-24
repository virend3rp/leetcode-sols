// Last updated: 4/24/2026, 10:16:14 PM
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 0; // Pointer for the valid index
        for (int num : nums) {
            if (j < 2 || num != nums[j - 2]) { // Allow at most two occurrences
                nums[j] = num;
                j++;
            }
        }
        
        return j; // Length of modified array
    }
};
