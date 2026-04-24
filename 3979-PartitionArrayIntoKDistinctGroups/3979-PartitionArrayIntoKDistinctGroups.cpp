// Last updated: 4/24/2026, 10:03:23 PM
class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        if(nums.size()%k!=0){
            return false;
        }
        int lim=nums.size()/k;
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
            if(mpp[nums[i]]>lim){
                return false;
            }
        }
        return true;
    }
};