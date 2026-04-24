// Last updated: 4/24/2026, 10:11:00 PM
class Solution {
public:
    int sumLesserEqualThan(vector<int>& nums, int goal) {
        int l = 0, r = 0;
        int n = nums.size();
        int count = 0;
        int sum = 0;
        
        while (r < n) {
            sum += nums[r];
            while (sum > goal && l <= r) {
                sum -= nums[l];
                l++;
            }
            count += (r - l + 1);
            r++;
        }
        
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int count1=sumLesserEqualThan(nums,goal);
        int count2=sumLesserEqualThan(nums,goal-1);
        return (count1-count2);
    }
};