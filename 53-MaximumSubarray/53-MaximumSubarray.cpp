// Last updated: 4/24/2026, 10:16:40 PM
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int maxi=nums[0];
        for(long long i=0;i<n;i++){
            sum=sum+nums[i];
            
            maxi=max(maxi,sum);
            if(sum<0){
                sum=0;
            }
        }
        return maxi;
    } 
};