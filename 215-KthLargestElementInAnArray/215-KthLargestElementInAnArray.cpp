// Last updated: 4/24/2026, 10:14:25 PM
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        priority_queue<int,vector<int>,greater<int>>minheap;
        for(int i =0;i<nums.size();i++)
        {
            minheap.push(nums[i]);
            if(minheap.size()>k){
                minheap.pop();
            }
        }
        int ans =minheap.top();
        return ans;
    }
};