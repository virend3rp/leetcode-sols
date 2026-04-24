// Last updated: 4/24/2026, 10:14:23 PM
class Solution {
public:
    vector<int> digits = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    void solve(int start, int sum, int k, int n, vector<int>& ds, vector<vector<int>>& final) {
        if (ds.size() == k) {
            if (sum == n) {
                final.push_back(ds);
            }
            return;
        }
        
        for (int i = start; i < digits.size(); i++) {
            if (sum + digits[i] > n) break;  // No need to proceed if the sum exceeds n
            ds.push_back(digits[i]);
            solve(i + 1, sum + digits[i], k, n, ds, final);  // Move to the next digit
            ds.pop_back();  // Backtrack
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> final;
        vector<int> ds;
        solve(0, 0, k, n, ds, final);  // Initial call with sum=0 and start=0
        return final;
    }
};
