// Last updated: 4/24/2026, 10:12:26 PM
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        int count[26] = {};
        for (char c : s1) count[c - 'a']++;
        for (int i = 0; i < s1.size(); i++) count[s2[i] - 'a']--;

        int matches = 0;
        for (int i = 0; i < 26; i++)
            if (count[i] == 0) matches++;

        if (matches == 26) return true;

        int windowSize = s1.size();
        for (int r = windowSize; r < s2.size(); r++) {
            int right = s2[r] - 'a';
            if (count[right] == 0) matches--;
            count[right]--;
            if (count[right] == 0) matches++;

            int left = s2[r - windowSize] - 'a';
            if (count[left] == 0) matches--;
            count[left]++;
            if (count[left] == 0) matches++;

            if (matches == 26) return true;
        }
        return false;
    }
};