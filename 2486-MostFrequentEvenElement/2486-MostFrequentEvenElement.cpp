// Last updated: 4/24/2026, 10:06:22 PM
class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int i : nums) {
            mp[i]++;
        }
        int maxi = INT_MIN;
        int ans = -1;
        for (auto it : mp) {
            int freq = it.second;
            int num = it.first;

            if (num % 2 == 0) {
                if (freq > maxi || (freq == maxi) && num < ans) {
                    maxi = freq;
                    ans = num;
                }
            }
        }
        return ans;
    }
};