// Last updated: 4/24/2026, 10:06:44 PM
class Solution {
public:
    string removeDigit(string number, char digit) {
        string maxResult = "";  // To store the maximum result

        for (int i = 0; i < number.size(); ++i) {
            if (number[i] == digit) {
                // Create a new string by skipping the current digit
                string temp = number.substr(0, i) + number.substr(i + 1);
                // Update the maxResult if the new string is greater
                if (temp > maxResult) {
                    maxResult = temp;
                }
            }
        }

        return maxResult;
    }
};
