// Last updated: 4/24/2026, 10:08:40 PM
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int cost = 0;
        
        for (int i = 1; i < colors.size(); i++) {
            if (colors[i] == colors[i - 1]) {
                cost += min(neededTime[i], neededTime[i - 1]);
                neededTime[i] = max(neededTime[i], neededTime[i - 1]);
            }
        }
        
        return cost;
    }
};