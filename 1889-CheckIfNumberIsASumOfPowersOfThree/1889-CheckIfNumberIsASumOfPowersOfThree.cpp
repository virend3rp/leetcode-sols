// Last updated: 4/24/2026, 10:08:07 PM
class Solution {
public:
    bool checkPowersOfThree(int n) {
    while (n > 0) {
        if (n % 3 == 2)  // If any digit in base 3 is 2, return false
            return false;
        n /= 3;  // Reduce n by removing the last base-3 digit
    }
    return true;
    }
};