// Last updated: 4/24/2026, 10:13:00 PM
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.size() < p.size()) return {};

        int count[26] = {};
        for (char c : p) count[c - 'a']++;
        for (char c : s.substr(0, p.size())) count[c - 'a']--;

        int matches = 0;
        for (int i = 0; i < 26; i++)
            if (count[i] == 0) matches++;

        vector<int> result;
        if (matches == 26) result.push_back(0);

        for (int right = p.size(); right < s.size(); right++) {
            int left = right - p.size();

            // add new right char
            int r = s[right] - 'a';
            if (count[r] == 0) matches--;
            count[r]--;
            if (count[r] == 0) matches++;

            // remove old left char
            int l = s[left] - 'a';
            if (count[l] == 0) matches--;
            count[l]++;
            if (count[l] == 0) matches++;

            if (matches == 26) result.push_back(left + 1);
        }
        return result;
    }
};