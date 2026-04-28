// Last updated: 4/28/2026, 3:23:25 PM
1class Solution {
2public:
3    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
4        int count = 0;
5        for (int a : arr1) {
6            bool valid = true;
7            for (int b : arr2) {
8                if (abs(a - b) <= d) {
9                    valid = false;
10                    break;
11                }
12            }
13            if (valid) count++;
14        }
15        return count;
16    }
17};