// Last updated: 4/24/2026, 10:06:01 PM
class Solution {
public:
    int numberOfCuts(int n) {
        if(n==1){
            return 0;
        }
        if(n%2==0){
            return n/2;
        }
        return n;
    }
};