// Last updated: 4/24/2026, 10:11:16 PM
class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long size = 0;
        
        // First, find the length of the decoded string
        for (char c : s) {
            if (isdigit(c)) {
                size *= (c - '0');  // Multiply by the digit (repeat)
            } else {
                size++;  // Increment for regular characters
            }
        }

        // Now, iterate over the string in reverse order to find the k-th character
        for (int i = s.size() - 1; i >= 0; i--) {
            k %= size;  // Find the position relative to the current size

            if (k == 0 && !isdigit(s[i])) {
                return string(1, s[i]);  // If it's the character we need, return it
            }

            if (isdigit(s[i])) {
                size /= (s[i] - '0');  // Reduce the size by the repeat factor
            } else {
                size--;  // Decrease size for regular characters
            }
        }

        return "";  // In case we don't find a solution (shouldn't happen)
    }
};