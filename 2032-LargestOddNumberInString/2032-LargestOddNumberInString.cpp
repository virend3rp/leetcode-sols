// Last updated: 4/24/2026, 10:07:46 PM
class Solution {
public:
    string largestOddNumber(string num) {
        // Start from the end of the string and find the first odd digit
        for (int i = num.size() - 1; i >= 0; i--) {
            if ((num[i] - '0') % 2 == 1) {
                // Return the substring from the beginning to this odd digit
                return num.substr(0, i + 1);
            }
        }
        // If no odd digit is found, return an empty string
        return "";
    }
};