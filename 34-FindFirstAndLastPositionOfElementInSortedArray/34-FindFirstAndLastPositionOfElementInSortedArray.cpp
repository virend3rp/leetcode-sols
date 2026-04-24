// Last updated: 4/24/2026, 10:16:59 PM
class Solution {
public:
    int lower_bound(vector<int>& arr, int n, int x) {
        int low = 0;
        int high = n - 1;
        int ans = n;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] >= x) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    int upper_bound(vector<int>& arr, int n, int x) {
        int low = 0;
        int high = n - 1;
        int ans = n;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] > x) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return {-1, -1};

        int lb = lower_bound(nums, n, target);
        int up = upper_bound(nums, n, target);
        
        // Check if the target is not present in the array
        if (lb == n || nums[lb] != target) {
            return {-1, -1};
        }

        return {lb, up - 1};
    }
};
