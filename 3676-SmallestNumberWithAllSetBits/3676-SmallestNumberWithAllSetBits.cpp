// Last updated: 4/24/2026, 10:04:10 PM
class Solution {
public:
    int smallestNumber(int n) {
        int b = log2(n) + 1;           // Calculate the number of bits
        return (1 << b) - 1;          // Return 2^b - 1
    }
};