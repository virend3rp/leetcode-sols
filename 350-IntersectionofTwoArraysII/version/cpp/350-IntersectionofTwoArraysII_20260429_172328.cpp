// Last updated: 4/29/2026, 5:23:28 PM
1class Solution {
2public:
3vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
4    unordered_map<int, int> freq;
5    for (int x : nums1) freq[x]++;
6    
7    vector<int> res;
8    for (int x : nums2)
9        if (freq[x]-- > 0) res.push_back(x);
10    return res;
11}
12};