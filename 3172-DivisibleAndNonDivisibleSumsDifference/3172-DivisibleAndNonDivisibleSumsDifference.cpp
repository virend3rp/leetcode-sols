// Last updated: 4/24/2026, 10:05:12 PM
class Solution {
public:
    int differenceOfSums(int n, int m) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {  
            if (i % m == 0) {
                sum -= i;
            } else {
                sum += i;
            }
        }
        return sum;    
    }
};