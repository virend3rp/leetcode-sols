// Last updated: 4/24/2026, 10:04:26 PM
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        for (int i = 0; i < nums.size(); i++)
            pq.push({nums[i], i});

        while (k--) {
            auto [val, idx] = pq.top(); pq.pop();
            nums[idx] = val * multiplier;
            pq.push({nums[idx], idx});
        }
        return nums;
    }
};