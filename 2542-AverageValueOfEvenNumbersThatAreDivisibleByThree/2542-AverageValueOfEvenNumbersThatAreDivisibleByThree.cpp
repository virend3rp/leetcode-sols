// Last updated: 4/24/2026, 10:06:10 PM
class Solution {
public:
    int averageValue(vector<int>& nums) {
        int n=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0 && nums[i]%3==0){
                sum+=nums[i];
                n++;
            }
        }
        return n==0?0:sum/n;
    }
};