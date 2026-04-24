// Last updated: 4/24/2026, 10:06:56 PM
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        set<int> st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        bool flag=true;
        while(flag){
            if(st.count(original)>0){
                original*=2;
            }
            else{
                flag=!flag;
            }
        }
        return original;
    }
};