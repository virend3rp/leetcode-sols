// Last updated: 4/24/2026, 10:10:45 PM
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
    int left = 0, zeros = 0, result = 0;

    for (int right = 0; right < nums.size(); right++) {
        if (nums[right] == 0) zeros++;

        while (zeros > k) {
            if (nums[left] == 0) zeros--;
            left++;
        }

        result = max(result, right - left + 1);
    }
    return result;
}
};