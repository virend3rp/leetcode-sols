// Last updated: 4/24/2026, 10:10:38 PM
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int num = 0;
        vector<bool> div;
        
        for (int i = 0; i < nums.size(); i++) {
            num = (num * 2 + nums[i]) % 5;  // Keep only remainder to prevent overflow
            div.push_back(num == 0);
        }
        
        return div;
    }
};
