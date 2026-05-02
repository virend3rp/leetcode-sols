// Last updated: 5/2/2026, 11:47:41 AM
1class Solution {
2public:
3    int rotatedDigits(int n) {
4        int rot[10] = {0, 1, 5, -1, -1, 2, 9, -1, 8, 6};
5        int count = 0;
6        
7        for (int x = 1; x <= n; x++) {
8            int tmp = x;
9            bool valid = true, changed = false;
10            while (tmp) {
11                int d = tmp % 10;
12                if (rot[d] == -1) { valid = false; break; }
13                if (rot[d] != d)   changed = true;
14                tmp /= 10;
15            }
16            if (valid && changed) count++;
17        }
18        return count;
19    }
20};