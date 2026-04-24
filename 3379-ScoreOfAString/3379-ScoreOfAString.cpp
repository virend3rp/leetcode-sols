// Last updated: 4/24/2026, 10:04:47 PM
class Solution {
public:
    int scoreOfString(string s) {
        int score = 0;
        for (size_t i = 0; i < s.length() - 1; i++) {
            score += abs(s[i] - s[i + 1]);
        }
        return score;
    }
};