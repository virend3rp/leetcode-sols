// Last updated: 4/24/2026, 10:17:16 PM
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int closest=0;
        int minDiff=INT_MAX;
        for(int i=0;i<nums.size()-2;i++){
            int j=i+1;
            int k=nums.size()-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==target){
                    return sum;
                }
                if(sum<target){
                    j++;
                }
                else{
                    k--;
                }
                int diff=abs(sum-target);
                if(diff<minDiff){
                    minDiff=diff;
                    closest=sum;
                }
            }
        }
        return closest;
    }
};