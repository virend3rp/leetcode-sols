// Last updated: 4/24/2026, 10:05:42 PM
class Solution {
public:
bool canFormSubsequence(const vector<int>& arr, int k, int min_value) {
    int count = 0;
    bool take_next = true; // Ensures non-contiguity

    for (int num : arr) {
        if (take_next && num <= min_value) {
            count++;
            take_next = false; // Skip the next element to ensure non-contiguity
        } else {
            take_next = true; // Reset to allow taking the next valid number
        }

        if (count >= k) return true;
    }

    return false;
}
    int minCapability(vector<int>& arr, int k) {
        int left = *min_element(arr.begin(), arr.end());
        int right = *max_element(arr.begin(), arr.end());
        int result = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canFormSubsequence(arr, k, mid)) {
                result = mid;  // Try for a larger minimum value
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return result;
    }
};