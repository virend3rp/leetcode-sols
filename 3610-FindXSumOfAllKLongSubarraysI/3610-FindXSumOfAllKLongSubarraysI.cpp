// Last updated: 4/24/2026, 10:04:21 PM
class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ans;
        int n = nums.size();
        for (int start = 0; start <= n - k; start++) {
            map<int, int> freq;
            for (int i = start; i < start + k; i++) {
                freq[nums[i]]++;
            }
            priority_queue<pair<int, int>> maxHeap;
            for (auto& [element, count] : freq) {
                maxHeap.push({count, element});
            }
            int xsum = 0;
            int count = 0;
            while (!maxHeap.empty() && count < x) {
                int freq = maxHeap.top().first;
                int element = maxHeap.top().second;
                maxHeap.pop();
                xsum += freq * element;
                count++;
            }
            ans.push_back(xsum);
        }

        return ans;
    }
};
