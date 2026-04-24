// Last updated: 4/24/2026, 10:14:38 PM
class Solution {
public:
    int largestPowerOf2(int n) {
        if (n < 1) return 0;
        n |= (n >> 1);
        n |= (n >> 2);
        n |= (n >> 4);
        n |= (n >> 8);
        n |= (n >> 16); // For 32-bit integers
        return n - (n >> 1);
    }

    int rangeBitwiseAnd(int left, int right) {
        int shift = 0;
        while (left < right) {
            left >>= 1;
            right >>= 1;
            shift++;
        }
        return left << shift;
    }
};
