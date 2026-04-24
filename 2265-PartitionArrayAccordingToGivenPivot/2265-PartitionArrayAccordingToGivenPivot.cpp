// Last updated: 4/24/2026, 10:07:00 PM
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> lesser;
        vector<int> greater;
        int count = 0;

        // Separate elements into lesser, greater, and count occurrences of pivot
        for (int num : nums) {
            if (num < pivot) {
                lesser.push_back(num);
            } else if (num > pivot) {
                greater.push_back(num);
            } else {
                count++;
            }
        }

        // Insert pivot elements in the middle
        while (count > 0) {
            lesser.push_back(pivot);
            count--;
        }

        // Append greater elements at the end
        lesser.insert(lesser.end(), greater.begin(), greater.end());

        return lesser;
    }
};
