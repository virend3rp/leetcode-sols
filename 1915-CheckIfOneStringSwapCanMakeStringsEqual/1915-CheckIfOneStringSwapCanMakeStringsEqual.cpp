// Last updated: 4/24/2026, 10:08:03 PM
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1.length() != s2.length()) return false;
        vector<int> diff; // Stores indexes where s1 and s2 differ
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) {
                diff.push_back(i);
            }
        }
        int count = diff.size();
        if (count == 0) return true; // Strings are already equal
        if (count == 2) { // Only one swap should make them equal
            return s1[diff[0]] == s2[diff[1]] && s1[diff[1]] == s2[diff[0]];
        }
        return false; // More than 2 differences mean swapping cannot fix it
    }
};
