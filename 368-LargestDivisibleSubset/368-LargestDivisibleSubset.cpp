// Last updated: 4/24/2026, 10:13:24 PM
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};

        // Step 1: Sort the array to ensure that every subset is in increasing order
        sort(nums.begin(), nums.end());

        // Step 2: Initialize dp array and hash array
        vector<int> dp(n, 1);       // dp[i] stores the size of the largest divisible subset ending at index i
        vector<int> hash(n);        // hash[i] points to the previous index in the subset

        int maxSize = 1;            // Maximum size of the subset
        int lastIndex = 0;          // Index of the last element in the largest subset

        // Step 3: Fill dp and hash arrays
        for (int i = 1; i < n; i++) {
            hash[i] = i;            // Initialize hash[i] to point to itself
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
            }
            // Update maxSize and lastIndex if we found a larger subset
            if (dp[i] > maxSize) {
                maxSize = dp[i];
                lastIndex = i;
            }
        }

        // Step 4: Reconstruct the largest divisible subset
        vector<int> ans;
        ans.push_back(nums[lastIndex]);
        while (hash[lastIndex] != lastIndex) {  // Stop when we reach the starting element of the subset
            lastIndex = hash[lastIndex];
            ans.push_back(nums[lastIndex]);
        }

        // Step 5: Reverse the result to return it in increasing order
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
