// Last updated: 4/24/2026, 10:04:33 PM
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int count = 0;
        int run = 1;

        // Iterate n + k - 1 to cover the circular wrap
        for (int i = 1; i < n + k - 1; i++) {
            int cur = colors[i % n];
            int prev = colors[(i - 1) % n];

            if (cur != prev) {
                run++;
            } else {
                run = 1;
            }

            if (run >= k) count++;
        }

        return count;
    }
};