// Last updated: 4/24/2026, 10:09:46 PM
class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int n = s1.size();
        
        int xyPatterns = 0, yxPatterns = 0;   
        for(int i = 0; i < n; i ++) {
            if(s1[i] == 'x' and s2[i] == 'y') {
                xyPatterns ++;
            }
            else if(s1[i] == 'y' and s2[i] == 'x') {
                yxPatterns ++;
            }
        }

        return ((xyPatterns % 2) == (yxPatterns % 2)) ? ((xyPatterns / 2) + (yxPatterns / 2)) + ((xyPatterns % 2) + (yxPatterns % 2)) : -1;
    }
};