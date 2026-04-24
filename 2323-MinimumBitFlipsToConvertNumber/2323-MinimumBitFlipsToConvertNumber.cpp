// Last updated: 4/24/2026, 10:06:48 PM
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans=start^goal;
        int cnt=0;
        while(ans>0){
            ans&=ans-1;
            cnt++;
        }
        return cnt;
        
    }
};