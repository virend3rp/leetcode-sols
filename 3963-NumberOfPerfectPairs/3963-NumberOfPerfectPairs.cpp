// Last updated: 4/24/2026, 10:03:29 PM
class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
         int n=nums.size();
         vector<long long> arr(n);
         for(int i=0;i<n;i++){
             arr[i]= llabs((long long) nums[i]);
        }
         sort(arr.begin(),arr.end());
         long long ans=0;
         int j=0;
         for(int i=0;i<n;i++){
             while(j<n && arr[j]<=2*arr[i])j++;
             long long count=j-i-1;
             ans+=count;
         }
        return ans;
    }
};