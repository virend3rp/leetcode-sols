// Last updated: 4/24/2026, 10:07:08 PM
class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if (n % 2 != 0) return false; // A valid string must have an even length
        
        int openCount = 0; // Tracks the balance of '(' and ')'
        int flexibleCount = 0; // Tracks the number of unlocked positions
        
        // Forward pass: Check if ')' can be balanced
        for (int i = 0; i < n; ++i) {
            if (locked[i] == '1') {
                if (s[i] == '(') ++openCount;
                else --openCount;
            } else {
                ++flexibleCount;
            }
            if (openCount + flexibleCount < 0) return false; // Too many ')'
        }
        
        openCount = 0;
        flexibleCount = 0;

        // Backward pass: Check if '(' can be balanced
        for (int i = n - 1; i >= 0; --i) {
            if (locked[i] == '1') {
                if (s[i] == ')') ++openCount;
                else --openCount;
            } else {
                ++flexibleCount;
            }
            if (openCount + flexibleCount < 0) return false; // Too many '('
        }

        return true;
    }
};
