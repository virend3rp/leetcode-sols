// Last updated: 4/24/2026, 10:07:27 PM
class Solution {
public:

int maximumDifference(vector<int>& nums) {
    int n = nums.size();
    if (n < 2) return -1;

    int max_diff = -1;
    int curr_max = nums[n - 1];

    for (int right = n - 2; right >= 0; --right) {
        if (nums[right] < curr_max) {
            max_diff = max(max_diff, curr_max - nums[right]);
        } else {
            curr_max = nums[right];
        }
    }

    return max_diff;
}
};