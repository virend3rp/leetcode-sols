// Last updated: 4/24/2026, 10:12:00 PM
class Solution {
public:
    bool check(const string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            ++i;
            --j;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j]) {
                return check(s, i + 1, j) || check(s, i, j - 1);
            }
            ++i;
            --j;
        }
        return true;
    }
};
