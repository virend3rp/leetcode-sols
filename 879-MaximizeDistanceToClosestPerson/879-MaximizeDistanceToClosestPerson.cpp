// Last updated: 4/24/2026, 10:11:24 PM
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int lastSet = -1;
        int maxgap = 0;  
        int firstGap = 0;
        int lastGap = 0; 
        for (int i = 0; i < n; i++) {
            if (seats[i] == 1) {
                firstGap = i; 
                lastSet = i;
                break;
            }
        }
        for (int i = lastSet + 1; i < n; i++) {
            if (seats[i] == 1) {
                maxgap = max(maxgap, i - lastSet);
                lastSet = i;
            }
        }
        lastGap = n - 1 - lastSet;
        return max({firstGap, maxgap / 2, lastGap});
    }
};
