// Last updated: 4/24/2026, 10:13:19 PM
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) i++; 
            j++; 
        }
        return i == s.size();  // If `i` reaches `s.size()`, all chars in `s` were found in order
    }
};