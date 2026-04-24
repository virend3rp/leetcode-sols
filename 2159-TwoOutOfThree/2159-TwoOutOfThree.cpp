// Last updated: 4/24/2026, 10:07:25 PM
class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_map<int, int> count;

        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());
        unordered_set<int> s3(nums3.begin(), nums3.end());

        for (int x : s1) count[x]++;
        for (int x : s2) count[x]++;
        for (int x : s3) count[x]++;

        vector<int> result;
        for (auto &p : count) {
            if (p.second >= 2) {
                result.push_back(p.first);
            }
        }

        return result;
    }
};