// Last updated: 4/24/2026, 10:05:49 PM
class Solution {
public:
    long long square(long long n) {
    return n * n;
}
    long long coloredCells(int n) {
        return square(n)+square(n-1); 
    }
};