// Last updated: 4/24/2026, 10:14:27 PM
class Solution {
public:
    int f(vector<int>& nums,int start,int end){
        int prev=nums[start];
        int prev2=0;
        for(int i=start+1;i<end;i++){
            int take =nums[i];
            if(i>1) take=take+prev2;

            int not_take=0+prev;
            int curi=max(not_take,take);
            prev2=prev;
            prev=curi;
        }

    return prev; 
    }
    int rob(vector<int>& nums) {
        int n= nums.size();
        if(n==1){
            return nums[0];
        }
        int r1=f(nums,0,n-1);
        int r2=f(nums,1,n);
        return max(r1,r2);
    }
};