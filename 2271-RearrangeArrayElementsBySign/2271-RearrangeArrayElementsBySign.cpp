// Last updated: 4/24/2026, 10:06:58 PM
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>arr(n,0);
        int positiveindex=0,negativeindex=1;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                arr[positiveindex]=nums[i];
                positiveindex+=2;
            }
            else{
                arr[negativeindex]=nums[i];
                negativeindex+=2;
            }
        }
        return arr;
    }
};