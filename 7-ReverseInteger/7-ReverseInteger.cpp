// Last updated: 4/24/2026, 10:17:30 PM
class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        int sign = 1;
        
        if (x < 0) {
            sign = -1;
            if(x<=INT_MIN){
                return 0;
            }
            else if (x>=INT_MAX){
                return 0;
            }            
            x = -x;
        }
        
        while (x > 0) {
            // Check for overflow before multiplying by 10
            if (ans > (INT_MAX - x % 10) / 10) {
                return 0; // Overflow case
            }
            ans = ans * 10 + x % 10;
            x = x / 10;
        }
        
        return ans * sign;
    }
};