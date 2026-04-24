// Last updated: 4/24/2026, 10:03:38 PM
class Solution {
public:
    vector<int> findCoins(vector<int>& numWays) {
        int n=numWays.size();
        numWays.insert(numWays.begin(),0);
        vector<int> dp(n+1,0);
        dp[0]=1;

        vector<int> result;
       for (int coin = 1; coin <= n; ++coin) {
                if (dp[coin] < numWays[coin]) {
                      result.push_back(coin);
                      for (int i = coin; i <= n; ++i) {
                          dp[i] += dp[i - coin];
                      }
                  }
              }

        for (int i = 1; i <= n; ++i) {
            if (dp[i] != numWays[i]) return {};
        }

        return result;
    }
};