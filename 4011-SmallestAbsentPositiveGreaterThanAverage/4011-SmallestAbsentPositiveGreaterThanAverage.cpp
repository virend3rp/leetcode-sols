// Last updated: 4/24/2026, 10:03:27 PM
class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        if (nums.empty()) return 1; 

        long long sum = 0;                      
        unordered_set<int> seen;                   
        seen.reserve(nums.size()*2 + 1);

        for (int v : nums) { sum += v; seen.insert(v); }

        long long avg = sum / (long long)nums.size(); 
        int x = (int)avg + 1;
        if (x < 1) x = 1;

        while (seen.count(x)) ++x;
        return x;
    }
};