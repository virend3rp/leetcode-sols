// Last updated: 4/24/2026, 10:03:25 PM
class Solution {
public:
    int maxXorSubsequences(vector<int>& nums) {
        const int B=32;
        vector<int> bas(B,0);
        for(int x:nums){
            int v=x;
            for(int b=B-1;b>=0 && v; --b){
                if(!(v&(1<<b))) continue;
                if(!bas[b]){bas[b] =v; break;}
                v^=bas[b];
            }
        }
        int ans=0;
        for(int b=B-1;b>=0;--b){
            if((ans^bas[b])>ans) ans^=bas[b];
        }
        return ans;
    }
};