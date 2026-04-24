// Last updated: 4/24/2026, 10:03:51 PM
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int rem = 0;

        for (int i = 0; i < n; i++) {
            bool placed = false;
            for (int j = 0; j < n; j++) {
                if (baskets[j] != -1 && fruits[i] <= baskets[j]) {
                    baskets[j] = -1;
                    placed = true;
                    break;
                }
            }

            if (!placed)
                rem++;
        }

        return rem;
    }
};