// Last updated: 4/24/2026, 10:17:15 PM
class Solution {
public:
    // Mapping of digits to corresponding letters
    vector<string> digitMap = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    void solve(int ind, string digits, string &temp, vector<string> &ds) {
        // Base case: If the index equals the length of the digits, we have a valid combination
        if(ind == digits.length()) {
            if(!temp.empty()) {
                ds.push_back(temp);
            }
            return;
        }
        
        // Get the letters corresponding to the current digit
        string letters = digitMap[digits[ind] - '0'];
        
        // Loop through each letter and recursively solve for the next digit
        for(char letter : letters) {
            temp.push_back(letter); // Add letter to current combination
            solve(ind + 1, digits, temp, ds); // Recurse to the next digit
            temp.pop_back(); // Backtrack and remove the letter
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ds;
        if(digits.empty()) return ds; // Edge case: empty input
        string temp = "";
        solve(0, digits, temp, ds);
        return ds;
    }
};