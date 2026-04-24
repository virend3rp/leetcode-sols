// Last updated: 4/24/2026, 10:13:52 PM
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size=nums.size();
        int sum=(size+1)*(size)/2;
        for(int i=0;i<size;i++){
            sum=sum-nums[i];
        }
        return sum;
    }
};