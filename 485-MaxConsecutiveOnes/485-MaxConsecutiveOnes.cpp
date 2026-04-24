// Last updated: 4/24/2026, 10:12:49 PM
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                count=count+1;
            }else{
                count=0;
            }
            maxi=max(count,maxi);
        }
        return maxi;
    }
};