// Last updated: 4/24/2026, 10:04:56 PM
class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        if(nums.size()%2!=0) return false;
        unordered_map<int,int> mpp;
        int count=0;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
            count=max(count,mpp[nums[i]]);
        }
        if(count>2){
            return false;
        }
        return true;
    }
};