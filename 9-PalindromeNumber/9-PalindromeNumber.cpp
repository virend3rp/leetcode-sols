// Last updated: 4/24/2026, 10:17:23 PM
class Solution {
public:
    bool isPalindrome(int x) {
        long  long  a=0;
        long long  c=x;
        if(x<0){
            return false;
        }
        while(x>0){
            long long r=x%10;
            x=x/10;
            a=(10*a)+r;
        }
        if(a==c){
            return true;
        }
        return false;
    }
};