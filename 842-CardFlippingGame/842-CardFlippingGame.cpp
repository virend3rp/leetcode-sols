// Last updated: 4/24/2026, 10:11:29 PM
class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        unordered_set<int> set;
        int n = fronts.size();

        for (int i = 0; i < n; i++) {
            if (fronts[i] == backs[i]) set.insert(fronts[i]);
        }

        int min = 1000000;

        for (int f : fronts) {
            if (set.find(f) == set.end()) min = std::min(min, f);
        }
        for (int b : backs) {
            if (set.find(b) == set.end()) min = std::min(min, b);
        }

        return min != 1000000 ? min : 0;
    }
};