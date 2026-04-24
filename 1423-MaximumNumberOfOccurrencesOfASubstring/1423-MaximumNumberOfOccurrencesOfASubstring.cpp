// Last updated: 4/24/2026, 10:09:32 PM
class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string, int> freq;
        int ans = 0;
        for (int i = 0; i <= s.size() - minSize; i++) {
            string window = s.substr(i, minSize);
            unordered_set<char> unique(window.begin(), window.end());
            if (unique.size() <= maxLetters) {
                freq[window]++;
                ans = max(ans, freq[window]);
            }
        }
        return ans;
    }
};