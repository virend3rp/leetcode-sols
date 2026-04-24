// Last updated: 4/24/2026, 10:03:31 PM
class Solution {
public:
    int minSensors(int n, int m, int k) {
        int side=2*k+1;
        int rows=(n+side-1)/side;
        int cols=(m+side-1)/side;
        return rows*cols;
    }
};