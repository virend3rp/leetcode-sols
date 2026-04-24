// Last updated: 4/24/2026, 10:10:35 PM
class Solution {
public:
    string removeOuterParentheses(string s) {
        string str = "";
        int balance = 0;
        for (auto ch : s) {
            if (ch == '(') {
                if (balance > 0) {
                    str += ch;
                }
                balance++;
            } else {
                balance--;
                if (balance > 0) {
                    str += ch;
                }
            }
        }
        return str;
    }
};