// Last updated: 4/24/2026, 10:16:48 PM
class Solution {
public:
// Helper function for backtracking
void backtrack(vector<int>& nums, vector<vector<int>>& result, vector<int>& temp, vector<bool>& used) {
    if (temp.size() == nums.size()) {
        result.push_back(temp); // Add the current permutation to the result
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        // Skip used elements or duplicate elements in the same recursion level
        if (used[i] || (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])) continue;

        // Choose the current number
        temp.push_back(nums[i]);
        used[i] = true;

        // Explore further
        backtrack(nums, result, temp, used);

        // Undo the choice (backtrack)
        temp.pop_back();
        used[i] = false;
    }
}

// Function to generate all unique permutations
vector<vector<int>> permute(vector<int>& nums) {
    sort(nums.begin(), nums.end()); // Sort to handle duplicates
    vector<vector<int>> result;
    vector<int> temp;
    vector<bool> used(nums.size(), false); // Track whether a number is used
    backtrack(nums, result, temp, used);
    return result;
}
};