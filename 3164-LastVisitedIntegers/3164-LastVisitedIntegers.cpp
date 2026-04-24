// Last updated: 4/24/2026, 10:05:13 PM
class Solution {
public:
    vector<int> lastVisitedIntegers(vector<int>& nums) {
        vector<int> seen, ans;
        int k = 0;
        for (int x : nums) {
            if (x != -1) { seen.push_back(x); k = 0; }
            else {
                k++;
                int idx = (int)seen.size() - k;
                ans.push_back(idx >= 0 ? seen[idx] : -1);
            }
        }
        return ans;
    }
};