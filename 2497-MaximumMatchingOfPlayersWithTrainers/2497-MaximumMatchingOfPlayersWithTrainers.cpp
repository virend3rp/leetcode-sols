// Last updated: 4/24/2026, 10:06:15 PM
class Solution {
public:
    int matchPlayersAndTrainers(std::vector<int>& players, std::vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int i = 0, j = 0, count = 0;
        while (i < players.size() && j < trainers.size()) {
            if (players[i] <= trainers[j]) {
                ++i;
                ++count;
            }
            ++j;
        }
        return count;
    }
};