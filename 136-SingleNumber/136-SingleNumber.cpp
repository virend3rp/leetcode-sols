// Last updated: 4/24/2026, 10:15:23 PM
class Solution {
public:
    int singleNumber(vector<int>& nums) {
       int ans=0;
	   for(auto x:nums)
	   ans^=x;
	   return ans;
    }
};