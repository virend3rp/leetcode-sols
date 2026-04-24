// Last updated: 4/24/2026, 10:06:05 PM
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        long long windowSum = 0, maxSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
            windowSum += nums[i];

            if (i >= k) {                         
                windowSum -= nums[i - k];
                freq[nums[i - k]]--;
                if (freq[nums[i - k]] == 0)
                    freq.erase(nums[i - k]);
            }

            if (i >= k - 1 && freq.size() == k)  
                maxSum = max(maxSum, windowSum);
        }

        return maxSum;
    }
};