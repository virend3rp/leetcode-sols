// Last updated: 4/24/2026, 10:16:53 PM
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector <int> visited(nums.size()+1,0);
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0 && nums[i]<=nums.size())
            visited[nums[i]]=1;
        }
        int final=0;
        for(int i=1;i<=nums.size();i++){
            if(visited[i]==0){
                return i;
            }
        }
        return nums.size()+1;
    }
};