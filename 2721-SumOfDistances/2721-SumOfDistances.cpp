// Last updated: 4/24/2026, 10:05:37 PM
class Solution {
public:
vector<long long> distance(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, vector<int>> indicesMap;
    for (int i = 0; i < n; i++)
        indicesMap[nums[i]].push_back(i);

    vector<long long> arr(n, 0);

    for (auto& [val, indices] : indicesMap) {
        int k = indices.size();
        if (k < 2) continue;
        long long total = 0;
        for (int idx : indices) total += idx;

        long long left_sum = 0;
        for (int p = 0; p < k; p++) {
            long long idx = indices[p];
            long long right_sum = total - left_sum - idx;

            arr[idx] = (p * idx - left_sum)
                     + (right_sum - (long long)(k - 1 - p) * idx);

            left_sum += idx;
        }
    }
    return arr;
}
};