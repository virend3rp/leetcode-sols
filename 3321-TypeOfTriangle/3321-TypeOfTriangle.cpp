// Last updated: 4/24/2026, 10:04:58 PM
class Solution {
public:
    string triangleType(vector<int>& nums) {
        if (nums[0] == nums[1] && nums[1] == nums[2])
            return "equilateral";
        else if ((nums[0] == nums[1] || nums[1] == nums[2] ||
                  nums[0] == nums[2]) &&
                 (nums[0] + nums[1] > nums[2]) &&
                 (nums[1] + nums[2] > nums[0]) && (nums[0] + nums[2] > nums[1]))
            return "isosceles";
        else if (nums[0] != nums[1] && nums[1] != nums[2] &&
                 nums[0] != nums[2] && (nums[0] + nums[1] > nums[2]) &&
                 (nums[1] + nums[2] > nums[0]) && (nums[0] + nums[2] > nums[1]))
            return "scalene";
        return "none";
    }
};