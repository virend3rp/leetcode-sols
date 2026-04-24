// Last updated: 4/24/2026, 10:12:36 PM
#include <vector>
#include <unordered_map>

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int count = 0;
        
        // Count the frequency of each element
        for (int num : nums) {
            freq[num]++;
        }
        
        // Check for k-diff pairs
        for (const auto& pair : freq) {
            int num = pair.first;
            int complement = num - k;
            
            if ((k > 0 && freq.count(complement)) || (k == 0 && freq[num] > 1)) {
                count++;
            }
        }
        
        return count;
    }
};

