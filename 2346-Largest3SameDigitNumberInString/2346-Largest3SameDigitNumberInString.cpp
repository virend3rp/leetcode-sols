// Last updated: 4/24/2026, 10:06:42 PM
class Solution {
public:
    string largestGoodInteger(string num) {
        int ans = -1; // to store what chars merge into
        string strAns = ""; // to store the value to return
        for (int i = 2; i < num.size(); ++i) { // go through from the third
            if (num[i] == num[i - 1] && num[i] == num[i - 2]) { // if current char is equal to the two previous ones
                string sub = num.substr(i - 2, 3); // take the string of this three chars
                int cur = stoi(sub); // convert this string of three chars to int
                if (cur > ans) { // if this int is greater than the answer - change the answer
                    ans = cur;
                    strAns = sub;
                }
            }
        }
        return strAns;
    }
};