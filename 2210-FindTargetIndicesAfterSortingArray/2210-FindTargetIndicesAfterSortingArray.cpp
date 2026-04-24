// Last updated: 4/24/2026, 10:07:14 PM
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int smaller = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < target) smaller++;
            if (nums[i] == target) count++;
        }

        vector<int> result;
        for (int i = 0; i < count; i++) {
            result.push_back(smaller + i);
        }

        return result;
    }
};
