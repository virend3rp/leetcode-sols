// Last updated: 4/24/2026, 10:14:10 PM
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && not (n & n - 1);
    }
};