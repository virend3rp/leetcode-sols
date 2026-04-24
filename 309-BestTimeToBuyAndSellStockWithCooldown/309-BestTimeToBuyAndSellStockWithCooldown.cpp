// Last updated: 4/24/2026, 10:13:44 PM
class Solution {
public:
    int f(int ind,int toBuy, vector<int>& prices, int n, vector<vector<int>>& dp) {
        if (ind >= n) {
            return 0;
        }

        if (dp[ind][toBuy] != -1) {
            return dp[ind][toBuy];
        }

        if (toBuy) {
            dp[ind][toBuy] = max(-prices[ind] + f(ind + 1,0, prices, n, dp),f(ind + 1,1, prices, n, dp));
        } 
        else {
            dp[ind][toBuy] = max(prices[ind] + f(ind + 2,1, prices, n, dp),f(ind + 1,0, prices, n, dp));
        }
        
        return dp[ind][toBuy];
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1)); // Memoization array
        return f(0,1, prices, n, dp);
    }
};
