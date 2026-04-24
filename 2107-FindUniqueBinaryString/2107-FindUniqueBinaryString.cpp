// Last updated: 4/24/2026, 10:07:35 PM
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string result = "";
        
        for (int i = 0; i < n; i++) {
            result += (nums[i][i] == '0') ? '1' : '0';  // Flip the diagonal bit
        }
        
        return result;
    }
};
