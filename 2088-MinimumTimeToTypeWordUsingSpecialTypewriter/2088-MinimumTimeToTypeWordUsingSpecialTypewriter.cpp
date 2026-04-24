// Last updated: 4/24/2026, 10:07:38 PM
class Solution {
public:
    int minTimeToType(string word) {
        int time = 0, cur = 0;
        for (char ch : word) {
            int nxt = ch - 'a';
            int diff = abs(cur - nxt);
            time += min(diff, 26 - diff) + 1;
            cur = nxt;
        }
        return time;
    }
};