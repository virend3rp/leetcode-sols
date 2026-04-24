// Last updated: 4/24/2026, 10:03:55 PM
class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int count0=0;
        int count1=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                count0++;
            }
            else{
                count1++;
            }
        }
        vector<int> final;
        while(count0>0){
            final.push_back(0);
            count0--;
        }
        while(count1>0){
            final.push_back(1);
            count1--;
        }
        return final;
    }
};