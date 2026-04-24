// Last updated: 4/24/2026, 10:06:43 PM
class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> lastSeen;
        int minLength = INT_MAX;

        for (int i = 0; i < cards.size(); i++) {
            if (lastSeen.find(cards[i]) != lastSeen.end()) {
                minLength = min(minLength, i - lastSeen[cards[i]] + 1);
            }
            lastSeen[cards[i]] = i; // Update the last seen index
        }

        return (minLength == INT_MAX) ? -1 : minLength;
    }
};