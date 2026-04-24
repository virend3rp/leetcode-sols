// Last updated: 4/24/2026, 10:13:26 PM
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
unordered_map<int, int> freq;
    vector<int> result;

    // Count frequencies of elements in nums1
    for (int num : nums1) {
        freq[num]++;
    }

    // Iterate through nums2 and check for intersection
    for (int num : nums2) {
        if (freq[num] > 0) {  // If num is in both arrays
            result.push_back(num);
            freq[num]--;  // Decrease count in the map
        }
    }

    return result;
    }
};