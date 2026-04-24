// Last updated: 4/24/2026, 10:03:40 PM
class Solution {
public:
    const int MOD = 1e9 + 7;
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        long long count = 0;
    
        unordered_map<int, int> rightFreq;
        for (int i = 0; i < n; ++i) {
            rightFreq[nums[i]]++;
        }
    
        unordered_map<int, int> leftFreq;
    
        for (int j = 0; j < n; ++j) {
            rightFreq[nums[j]]--; 
    
            int target = nums[j] * 2;
            count += (long long)leftFreq[target] * rightFreq[target];
            count %= MOD;
    
            leftFreq[nums[j]]++;
        }
    
        return (int)count;
    }
};