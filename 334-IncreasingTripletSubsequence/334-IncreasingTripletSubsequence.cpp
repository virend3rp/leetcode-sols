// Last updated: 4/24/2026, 10:13:33 PM
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
    int first = INT_MAX;
    int second = INT_MAX;

    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] <= first) {
            first = nums[i];  // smallest so far
        } else if (nums[i] <= second) {
            second = nums[i]; // second smallest
        } else {
            // Found nums[i] > second > first
            return true;
        }
    }

    return false;
    }
};