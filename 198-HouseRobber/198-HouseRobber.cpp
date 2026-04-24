// Last updated: 4/24/2026, 10:14:41 PM
class Solution {
public:
int rob(vector<int>& nums) {
    int prev2 = 0;
    int prev1 = 0;

    for (int x : nums) {
        int curr = max(prev1, prev2 + x);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
};