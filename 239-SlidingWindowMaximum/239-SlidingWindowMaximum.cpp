// Last updated: 4/24/2026, 10:14:01 PM
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq; // Stores indices of the elements

        for (int i = 0; i < nums.size(); i++) {
            // Remove indices of elements not in the current window
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }

            // Remove elements from deque that are smaller than the current element
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            // Add the current element's index to the deque
            dq.push_back(i);

            // Once we have processed at least k elements, the max of the current window is at dq.front()
            if (i >= k - 1) {
                res.push_back(nums[dq.front()]);
            }
        }

        return res;
    }
};
