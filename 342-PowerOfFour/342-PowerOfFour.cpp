// Last updated: 4/24/2026, 10:13:31 PM
class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;  // Power of 4 must be positive
        int num = n;  // No need to take absolute value, as n > 0
        int oneCount = 0, zeroCount = 0;
        while (num > 0) {
            if ((num & 1) == 0) zeroCount++;  // Count trailing zeros
            if ((num & 1) == 1) oneCount++;   // Count number of ones
            num >>= 1;
        }

        return oneCount == 1 && zeroCount % 2 == 0;
    }
};