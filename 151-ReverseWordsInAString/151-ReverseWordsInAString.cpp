// Last updated: 4/24/2026, 10:15:07 PM
class Solution {
public:
    string reverseWords(string s) {
        int left = 0;
        int right = s.length() - 1;
        
        // Step 1: Trim leading and trailing spaces
        while (left <= right && s[left] == ' ') left++;
        while (right >= left && s[right] == ' ') right--;
        
        string temp = "";
        string ans = "";
        
        // Step 2: Iterate through the string and process each word
        while (left <= right) {
            char ch = s[left];
            
            // If the character is not a space, add it to the current word (temp)
            if (ch != ' ') {
                temp += ch;
            } 
            // If a space is encountered, add the current word to the result
            else if (temp != "") {
                // Add the word to the front of the result to reverse word order
                if (ans != "") ans = temp + " " + ans;
                else ans = temp;
                temp = "";
            }
            left++;
        }
        
        // Step 3: Add the last word to the result (if any)
        if (temp != "") {
            if (ans != "") ans = temp + " " + ans;
            else ans = temp;
        }
        
        return ans;
    }
};
