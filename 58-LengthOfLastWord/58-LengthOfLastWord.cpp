// Last updated: 4/24/2026, 10:16:34 PM
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int count = 0;
        int idx = n - 1;

        // Skip trailing spaces
        while (idx >= 0 && s[idx] == ' ') {
            idx--;
        }

        // Count the length of the last word
        while (idx >= 0 && s[idx] != ' ') {
            count++;
            idx--;
        }

        return count;
    }
};
