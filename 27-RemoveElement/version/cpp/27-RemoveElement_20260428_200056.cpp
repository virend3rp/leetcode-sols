// Last updated: 4/28/2026, 8:00:56 PM
1class Solution {
2public:
3    int removeElement(vector<int>& nums, int val) {
4        int i = 0;
5        
6        for(int j =  0; j < nums.size(); j++){
7            if(nums[j] != val){
8                swap(nums[j], nums[i]);
9                i++;
10            }
11        }
12        return i;
13    }
14
15};