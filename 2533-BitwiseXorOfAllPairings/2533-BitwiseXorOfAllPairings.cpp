// Last updated: 4/24/2026, 10:06:11 PM
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        int ans1 = 0;
        if (nums2.size() % 2 != 0) {
            for (int i = 0; i < nums1.size(); i++) {
                ans = ans ^ nums1[i];
            }
        }
        if (nums1.size() % 2 != 0) {
            for (int i = 0; i < nums2.size(); i++) {
                ans1 = ans1 ^ nums2[i];
            }
        }
        return ans ^ ans1;
    }
};