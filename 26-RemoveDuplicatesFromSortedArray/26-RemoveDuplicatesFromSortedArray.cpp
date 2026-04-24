// Last updated: 4/24/2026, 10:17:06 PM
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int j = 0; // Pointer for the new unique array
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[j]) { // Only update if a new unique element is found
                j++;
                nums[j] = nums[i];
            }
        }
        return j + 1; // Length of unique elements
    }
};
