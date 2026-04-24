// Last updated: 4/24/2026, 10:17:39 PM
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            int a=nums[i];
            int b=target-a;
            if(mpp.find(b)!=mpp.end()){
                return {i,mpp[b]};
            }
            mpp[a]=i;
        }
        return {-1,-1};
    }
};