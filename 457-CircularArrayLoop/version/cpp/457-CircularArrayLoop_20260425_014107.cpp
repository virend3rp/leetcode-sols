// Last updated: 4/25/2026, 1:41:07 AM
1class Solution {
2public:
3    int getNext(int curr, vector<int>& nums){
4        int n = nums.size();
5        return ((curr + nums[curr]) % n + n) % n;
6    }
7
8    bool circularArrayLoop(vector<int>& nums) {
9        int n = nums.size();
10        
11        for(int i = 0; i < n; i++){
12            if(nums[i] == 0) continue; 
13            int slow = i, fast = i;
14            int iniDir = nums[i];
15            while(true){
16                if(nums[slow] * iniDir <= 0) break;
17                if(nums[fast] * iniDir <= 0) break;
18                int nextFast = getNext(fast, nums);
19                if(nums[nextFast] * iniDir <= 0) break;
20                slow = getNext(slow, nums);
21                fast = getNext(nextFast, nums);
22                if(slow == fast){
23                    if(slow == getNext(slow, nums)) break;
24                    else return true;
25                } 
26            }
27            int curr = i;
28            while(nums[curr] * iniDir > 0){
29                int next = getNext(curr, nums);
30                nums[curr] = 0;
31                curr = next;
32            }
33        }
34        return false;
35    }
36};