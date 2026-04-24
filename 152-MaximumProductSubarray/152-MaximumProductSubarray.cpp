// Last updated: 4/24/2026, 10:15:06 PM
class Solution {
public:
    int maxProduct(vector<int>& nums) {
    int curMax = nums[0], curMin = nums[0], ans = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        int x = nums[i];
        int tempMax = max({x, curMax * x, curMin * x});
        int tempMin = min({x, curMax * x, curMin * x});
        curMax = tempMax;
        curMin = tempMin;
        ans = max(ans, curMax);
    }
    return ans;
    }
};