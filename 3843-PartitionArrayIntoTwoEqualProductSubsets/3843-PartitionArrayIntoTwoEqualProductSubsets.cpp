// Last updated: 4/24/2026, 10:03:44 PM
class Solution {
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        if (target == 0) return false;  // log(0) is undefined
        
        double logProduct = 0;
        for (int it : nums) {
            if (it == 0) return target == 0;
            logProduct += log(it);
        }

        double logTarget = log(target) * 2;
        
        return abs(logProduct - logTarget) < 1e-9; // Use precision threshold
    }
};
