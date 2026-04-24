// Last updated: 4/24/2026, 10:06:18 PM
class Solution {
public:
    int smallestEvenMultiple(int n) {
        if(n==1){
            return 2;
        }
        if(n%2==0){
            return n;
        }
        return 2*n;
    }
};