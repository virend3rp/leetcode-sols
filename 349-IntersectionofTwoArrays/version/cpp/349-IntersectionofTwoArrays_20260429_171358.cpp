// Last updated: 4/29/2026, 5:13:58 PM
1class Solution {
2public:
3vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
4    unordered_set<int> s(nums1.begin(), nums1.end());
5    vector<int> res;
6    for (int x : nums2)
7        if (s.erase(x)) res.push_back(x);
8    return res;
9}
10};