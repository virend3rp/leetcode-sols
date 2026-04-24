// Last updated: 4/24/2026, 11:04:59 PM
1class Solution {
2public:
3    int minSizeSubarray(vector<int>& nums, int target) {
4        int n = nums.size();
5        long long totalSum = 0;
6        for(int x : nums) totalSum += x;
7        
8        int fullCycles = target / totalSum;
9        int remainder = target % totalSum;
10        
11        if(remainder == 0) return fullCycles * n;
12        int ans = INT_MAX;
13        long long currSum = 0;
14        int left = 0;
15        
16        for(int right = 0; right < 2 * n; right++){
17            currSum += nums[right % n];
18            while(currSum > remainder){
19                currSum -= nums[left % n];
20                left++;
21            }
22            if(currSum == remainder)
23                ans = min(ans, right - left + 1);
24        }
25        
26        return ans == INT_MAX ? -1 : ans + fullCycles * n;
27    }
28};