// Last updated: 4/24/2026, 10:14:22 PM
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i] == nums[i+1]){
                return true;
            }
        }
        return false;
    }
};