// Last updated: 4/24/2026, 10:07:58 PM
class Solution {
public:
    int minOperations(vector<int>& nums) {
        if(nums.size()<2){
            return 0;
        }
        int op=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=nums[i-1]){
            int temp=nums[i];
            nums[i]=nums[i-1]+1;
            op+=nums[i]-temp;
            }
        }
        return op;
    }
};