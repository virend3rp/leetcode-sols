// Last updated: 4/24/2026, 10:04:55 PM
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int operations=0;
        priority_queue<long long, vector<long long>, greater<long long >> pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        while(pq.top()<k){
            long long x=pq.top();
            pq.pop();
            long long  y=pq.top();
            pq.pop();
            long long  nentry=2*min(x,y)+max(x,y);
            pq.push(nentry);
            operations++;
        }
        return operations;
    }
};