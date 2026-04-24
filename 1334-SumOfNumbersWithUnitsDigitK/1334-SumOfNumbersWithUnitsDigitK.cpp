// Last updated: 4/24/2026, 10:09:52 PM
class Solution {
public:
    int minimumNumbers(int num, int k) {
        if (num == 0) return 0;

        for (int x = 1; x <= 10; ++x) {
            int sum = x * k;
            if (sum > num) break;
            if ((num - sum) % 10 == 0) return x;
        }

        return -1;
    }
};
