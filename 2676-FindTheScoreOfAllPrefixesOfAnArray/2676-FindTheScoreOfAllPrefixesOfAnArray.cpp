// Last updated: 4/24/2026, 10:05:45 PM
class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        vector<long long> score(nums.size());
        vector<long long> conver(nums.size());
        int maxi=nums[0];
        conver[0]=nums[0]+maxi;
        for(int i=1;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
            conver[i]=nums[i]+maxi;
        }
        long long scored=0;
        for(int i=0;i<nums.size();i++){
            scored+=conver[i];
            score[i]=scored;
        }
        return score;
    }
};