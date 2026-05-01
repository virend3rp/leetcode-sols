// Last updated: 5/1/2026, 9:36:37 AM
1class Solution {
2public:
3    int maxRotateFunction(vector<int>& nums) {
4        int n = nums.size();
5        long long sum = 0, F = 0;
6        
7        for (int i = 0; i < n; i++) {
8            sum += nums[i];
9            F += (long long)i * nums[i];
10        }
11        
12        long long maxF = F;
13        for (int k = 1; k < n; k++) {
14            F += sum - (long long)n * nums[n - k];
15            maxF = max(maxF, F);
16        }
17        
18        return (int)maxF;
19    }
20};