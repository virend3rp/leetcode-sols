// Last updated: 4/24/2026, 10:14:14 PM
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if (nums.empty()) return ans; // Handle empty input

        int l = 0; // Left pointer to the start of the range
        for (int r = 0; r < nums.size(); ++r) {
            // Check if the current number breaks the consecutive range
            if (r + 1 == nums.size() || nums[r + 1] != nums[r] + 1) {
                string temp = to_string(nums[l]); // Start of the range
                if (l != r) {
                    temp += "->" + to_string(nums[r]); // Add the end of the range if more than one element
                }
                ans.push_back(temp); // Store the range
                l = r + 1; // Move the left pointer to the next range
            }
        }

        return ans;
    }
};
