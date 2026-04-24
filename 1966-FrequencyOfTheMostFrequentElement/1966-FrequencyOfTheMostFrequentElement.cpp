// Last updated: 4/24/2026, 10:07:54 PM
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0, result = 1;
        long sum = 0;

        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];

            while ((long)nums[right] * (right - left + 1) - sum > k)
                sum -= nums[left++];

            result = max(result, right - left + 1);
        }
        return result;
    }
};