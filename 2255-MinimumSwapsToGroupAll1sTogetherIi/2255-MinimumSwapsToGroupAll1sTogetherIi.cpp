// Last updated: 4/24/2026, 10:07:04 PM
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int totalOnes = count(nums.begin(), nums.end(), 1);
        
        if (totalOnes == 0 || totalOnes == n) return 0;
        int onesInWindow = 0;
        for (int i = 0; i < totalOnes; i++)
            onesInWindow += nums[i];

        int maxOnes = onesInWindow;
        for (int i = 1; i < n; i++) {
            onesInWindow += nums[(i + totalOnes - 1) % n]; 
            onesInWindow -= nums[i - 1];                    
            maxOnes = max(maxOnes, onesInWindow);
        }

        return totalOnes - maxOnes;  
    }
};