// Last updated: 4/24/2026, 10:09:58 PM
class Solution {
public:
    string makeFancyString(string s) {
        string result;
        int count = 1; // Start from 1 as we count consecutive characters
        
        result += s[0]; // Add first character

        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) {
                count++; // Increment count for consecutive same characters
            } else {
                count = 1; // Reset count if a new character appears
            }
            
            if (count < 3) {
                result += s[i]; // Append only if count < 3
            }
        }
        return result;
    }
};
