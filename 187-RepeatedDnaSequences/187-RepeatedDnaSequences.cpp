// Last updated: 4/24/2026, 10:14:48 PM
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() < 10) return {};
        unordered_map<string, int> freq;
        vector<string> result;
        string window = s.substr(0, 10);
        freq[window]++;
        for (int i = 10; i < s.size(); i++) {
            window = window.substr(1) + s[i];
            freq[window]++;
            if (freq[window] == 2) result.push_back(window);
        }
        return result;
    }
};