// Last updated: 4/24/2026, 10:08:54 PM
class Solution {
public:
    int xorOperation(int n, int start) {
        int ans=0;
        for(int i=0;i<n;i++){
            ans^=start + 2*i;
        }
        return ans;
        
    }
};