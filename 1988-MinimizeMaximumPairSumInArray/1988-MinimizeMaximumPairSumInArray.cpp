// Last updated: 4/24/2026, 10:07:51 PM
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxi=-1;
        int n= nums.size();
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]+nums[n-1-i]);
        }
        return maxi;
    }
};