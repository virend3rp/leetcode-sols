// Last updated: 4/24/2026, 10:07:15 PM
class Solution {
public:
 vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> maxHeap;

        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            maxHeap.push({nums[i], i});
        }
        vector<pair<int, int>> topK;
        for (int i = 0; i < k; ++i) {
            topK.push_back(maxHeap.top());
            maxHeap.pop();
        }
        sort(topK.begin(), topK.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        });


        vector<int> result;
        for (auto& p : topK) {
            result.push_back(p.first);
        }

        return result;
    }
};