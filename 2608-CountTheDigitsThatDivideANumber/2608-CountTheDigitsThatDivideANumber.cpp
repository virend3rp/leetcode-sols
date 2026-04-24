// Last updated: 4/24/2026, 10:05:54 PM
class Solution {
public:
    int countDigits(int num) {
       int n=num;
        int cnt=0;
        while(n){
            int r=n%10;
            n=n/10;
            if(num%r==0)cnt++;
        }
        return cnt; 
    }
};