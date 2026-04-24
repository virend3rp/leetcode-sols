// Last updated: 4/24/2026, 10:06:39 PM
class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l=0,r=0;
        int count=1;
        while(r<nums.size()){
            if(nums[r]-nums[l]>k){
                l=r;
                count++;
            }
            r++;
        }
        return count;
    }
};