// Last updated: 4/24/2026, 10:04:06 PM
class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        // storing frequencies of each element in nums
        map<int, int> mpp;
        for(int i=0; i<nums.size(); i++){
            mpp[nums[i]]++;
        }
        // the only subarray of size equal to nums.size() is nums itself,
        // thus, simply return the greatest element, no matter what it's frequency is
        if(k==nums.size()){
            return *max_element(nums.begin(), nums.end());
        }
        // calculate the greatest element with frequency=1
        int mx=INT_MIN;
        for(auto it:mpp){
            if(it.second==1 && it.first>mx){
                mx=it.first;
            }
        }
        // this greatest element `mx` will be the answer for the case where k equals 1
        // but if no such `mx` exists, return -1
        if(k==1){
            if(mx==INT_MIN){
                return -1;
            }
            return mx;
        }
        // now that all edge cases have been handled, the answer must be either first or 
        // last element of nums
        // however, if both have frequency > 1, return -1
        if(mpp[nums[0]]==1){
            if(mpp[nums[nums.size()-1]]==1){
                return max(nums[0], nums[nums.size()-1]);
            }
            else{
                return nums[0];
            }
        }
        else{
            if(mpp[nums[nums.size()-1]]==1){
                return nums[nums.size()-1];
            }
        }
        return -1;
    }
};