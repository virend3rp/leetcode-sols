// Last updated: 4/24/2026, 10:17:05 PM
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        
        for(int j =  0; j < nums.size(); j++){
            if(nums[j] != val){
                swap(nums[j], nums[i]);
                i++;
            }
        }
        return i;
    }

};