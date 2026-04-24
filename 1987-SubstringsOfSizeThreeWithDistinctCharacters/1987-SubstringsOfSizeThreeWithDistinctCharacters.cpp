// Last updated: 4/24/2026, 10:07:52 PM
class Solution {
public:
    int countGoodSubstrings(string s) {
        int count = 0;
        for (int i = 0; i + 2 < s.size(); i++) {
            if (s[i] != s[i+1] && s[i+1] != s[i+2] && s[i] != s[i+2])
                count++;
        }
        return count;
    }
};