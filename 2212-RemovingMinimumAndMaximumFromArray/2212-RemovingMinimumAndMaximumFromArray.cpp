// Last updated: 4/24/2026, 10:07:12 PM
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
    
    // Find the indices of the minimum and maximum elements
        int min_idx = min_element(nums.begin(), nums.end()) - nums.begin();
        int max_idx = max_element(nums.begin(), nums.end()) - nums.begin();
    
    // Ensure min_idx < max_idx for simplicity
        if (min_idx > max_idx) {
            swap(min_idx, max_idx);
        }

        // Option 1: Remove from the front
        int option1 = max_idx + 1;
        
        // Option 2: Remove from the back
        int option2 = n - min_idx;
        
        // Option 3: Remove one from the front and one from the back
        int option3 = (min_idx + 1) + (n - max_idx);

        // Return the minimum of the three options
        return min({option1, option2, option3});
    }
};