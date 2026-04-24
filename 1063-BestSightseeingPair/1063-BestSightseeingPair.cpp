// Last updated: 4/24/2026, 10:10:39 PM
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        
        int ans = 0;
        int a = values[0];
        for(int i = 1;i<values.size();i++){
            a--;
            int b = values[i];
            ans = max(ans,a+b);
            a = max(a,b);
        }
        return ans;
    }
};

// 8 1 5 2 6
// (8) => (7)(1) => (6)(5) => (5)(2) => 