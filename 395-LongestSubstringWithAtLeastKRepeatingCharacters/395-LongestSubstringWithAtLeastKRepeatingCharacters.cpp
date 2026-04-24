// Last updated: 4/24/2026, 10:13:17 PM
class Solution {
public:
    int longestSubstring(string s, int k) {
        if (s.size() == 0) return 0;
        unordered_map<char, int> freq;
        for (char ch : s) freq[ch]++;
        
        for (int i = 0; i < s.size(); i++) {
            if (freq[s[i]] < k) {
                int left = longestSubstring(s.substr(0, i), k);
                int right = longestSubstring(s.substr(i + 1), k);
                return max(left, right);
            }
        }
        return s.size(); // all chars appear >= k times
    }
};