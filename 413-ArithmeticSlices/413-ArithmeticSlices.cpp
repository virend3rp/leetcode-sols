// Last updated: 4/24/2026, 10:13:10 PM
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int result = 0, len = 2;

        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) {
                len++;
                result += len - 2;
            } else {
                len = 2;
            }
        }
        return result;
    }
};