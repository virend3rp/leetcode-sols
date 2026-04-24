// Last updated: 4/24/2026, 10:08:23 PM
class Solution {
public:
    int totalMoney(int n) {
        int weeks = n/7;
        int days = n%7;

        int daysMoney = 0;
        for(int i=1; i<=days; i++) daysMoney += weeks + i;

        if(weeks<1) return daysMoney;

        int totalMoney = weeks*28 + 7*((weeks-1)*(weeks))/2 + daysMoney;
        return totalMoney;
    }
};
