// Last updated: 4/24/2026, 10:16:17 PM
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() < t.length()) {
            return "";
        }

        unordered_map<char, int> charCount;
        for (char ch : t) {
            charCount[ch]++;
        }

        int targetCharsRemaining = t.length();
        int minWindow[2] = {0, INT_MAX}; 
        int startIndex = 0;

        for (int endIndex = 0; endIndex < s.length(); endIndex++) {
            char ch = s[endIndex];
            
            if (charCount[ch] > 0) {
                targetCharsRemaining--;
            }
            charCount[ch]--;

            while (targetCharsRemaining == 0) {
                if (endIndex - startIndex < minWindow[1] - minWindow[0]) {
                    minWindow[0] = startIndex;
                    minWindow[1] = endIndex;
                }

                char startChar = s[startIndex];
                charCount[startChar]++;
                
                if (charCount[startChar] > 0) {
                    targetCharsRemaining++;
                }

                startIndex++;
            }
        }

        return minWindow[1] == INT_MAX ? "" : s.substr(minWindow[0], minWindow[1] - minWindow[0] + 1);
    }
};
